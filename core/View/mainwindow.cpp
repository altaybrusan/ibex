#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpatientdialog.h"
#include "exposuredialog.h"
#include "QMessageBox"
#include "pacsnodesettingsdialog.h"
#include "LoadStudyDialog.h"
#include "worklistserversettingsdialog.h"
#include "worklistdialog.h"
#include <QSqlField>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "logindialog.h"
#include <QDateTime>
#include <QSqlRecord>
#include "dcmtk/dcmdata/dcuid.h"
#include "dcmtk/ofstd/ofstream.h"

int MACHINE_UID=001;

QString GenerateStudyID()
{
    QDateTime dt;
    QString _year = QString::number(dt.currentDateTime().date().year());
    QString _month = QString::number(dt.currentDateTime().date().month());
    QString _day = QString::number(dt.currentDateTime().date().day());
    QString _hour = QString::number(dt.currentDateTime().time().hour());
    QString _minutes = QString::number(dt.currentDateTime().time().minute());
    QString _seconds = QString::number(dt.currentDateTime().time().second());
    QString _machine = QString::number(MACHINE_UID);

    return _machine+_year+_month+_day+_hour+_minutes+_seconds;
}

inline void CenterWidgets(QWidget *widget, QWidget *host = 0) {
    if (!host)
        host = widget->parentWidget();

    if (host) {
        auto hostRect = host->geometry();
        widget->move(hostRect.center() - widget->rect().center());
    }
    else {
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width() - widget->width()) / 2;
        int y = (screenGeometry.height() - widget->height()) / 2;
        widget->move(x, y);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    wrkDlg(new WorkListDialog(this)),
    loginDlg(new LoginDialog(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loginDlg->setModal(true);
    CenterWidgets(loginDlg,this);
    loginDlg->show();



    _model= new QSqlTableModel(this,_database) ;
    _model->setTable("StudyTbl");
    _model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _model->select();

    _model2 = new QSqlTableModel(this,_database) ;
    _model2->setTable("WorkListTbl");
    _model2->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _model2->select();

    _dialog= new NewPatientDialog(this);
    connect(_dialog,SIGNAL(accepted()),this,SLOT(on_newPatient_accepted()));
    connect(wrkDlg,SIGNAL(NotifyRecoredSelected(QSqlRecord)),this,SLOT(on_Patient_selected(QSqlRecord)));
    connect(loginDlg,SIGNAL(accepted()),this,SLOT(on_Login_Successfully()));
    connect(loginDlg,SIGNAL(rejected()),this,SLOT(on_Login_Failed()));


}

MainWindow::~MainWindow()
{
     _model->submitAll();
    delete ui;
}

void MainWindow::on_action_New_Study_triggered()
{

    _dialog->setModal(true);
    _dialog->show();

}

void MainWindow::on_newPatient_accepted()
{
    //qDebug()<< "Dialog RESULT:"<<_dialog->result();
    //_model->setTable("StudyTbl");
    _model->select();
    qDebug()<<"Number of records: "<<_model->rowCount();
    QSqlRecord _record = _model->record();

    char uid[100];
    QString StudyId =GenerateStudyID();
    _record.setValue("studyid",StudyId);
    _record.setValue("viewid",_dialog->GetSelectedProceduresList().at(0));
    _record.setValue("seriesinstanceuid",dcmGenerateUniqueIdentifier(uid, SITE_SERIES_UID_ROOT));
    _record.setValue("seriesstartdatetime",QDateTime::currentDateTime().date().toString("yyyy.MM.dd"));
    QString sop =dcmGenerateUniqueIdentifier(uid, SITE_INSTANCE_UID_ROOT);
    _record.setValue("primarysopuid",sop);
    _record.setValue("secondarysopuid",sop+".1");
    _record.setValue("imageacqdatetime",QDateTime::currentDateTime().time().toString());
    /*
     *  SCHEDULED,
        INPROGRESS,
        SUSPENDED,
        COMPLETED,
        DISCONTINUED
     */
    _record.setValue("imagesendstatus","SCHEDULED");
    _record.setValue("imageprintstatus","SCHEDULED");
    _model->insertRecord(_model->rowCount(),_record);

    if(_model->submitAll())
    {
        qDebug()<<"Successfully sumited to the db.";
    }
    else
    {
        qDebug()<<"Failed to sumite to the db.";
    }


        QSqlRecord _record2 = _model2->record();
        // initialize the record with dummy data
        for(int a=0;a<=_record2.count();a++)
        {
            _record2.setValue(a,QString::number(1));
        }
        _record2.setValue("studyid: ",StudyId);
        _record2.setValue("accessionnum",_dialog->GetPatientInfo(NewPatientDialog::AccessionNumber));

        QString fullname;

        if(_dialog->GetPatientInfo(NewPatientDialog::MiddleName) != "")
        {
            fullname = _dialog->GetPatientInfo(NewPatientDialog::FirstName)+"^"+
                       _dialog->GetPatientInfo(NewPatientDialog::MiddleName)+"^"+
                       _dialog->GetPatientInfo(NewPatientDialog::LastName);
        }
        else
        {
            fullname = _dialog->GetPatientInfo(NewPatientDialog::FirstName)+"^"+
                       _dialog->GetPatientInfo(NewPatientDialog::LastName);
        }

        _record2.setValue("patientname",fullname);
        _record2.setValue("patientid",_dialog->GetPatientInfo(NewPatientDialog::PatientID));
        _record2.setValue("sex",_dialog->GetPatientInfo(NewPatientDialog::Gender));
        _record2.setValue("refphysician",_dialog->GetPatientInfo(NewPatientDialog::ReferrinPhysician));
        _record2.setValue("admittingtime",QDateTime::currentDateTime().date().toString(Qt::ISODate));
        _record2.setValue("studyinstanceuid",dcmGenerateUniqueIdentifier(uid, SITE_SERIES_UID_ROOT));
        _record2.setValue("visitcomment","LOCAL");
        _record2.setValue("studystatus","SCHEDULED");
        _record2.setValue("studystartdatetime",QDate::currentDate().toString(Qt::ISODate));


        //OTHER FIELDS ARE NOT INSERTED YET
        _model2->insertRecord(_model2->rowCount(),_record2);

        if(_model2->submitAll())
        {
            qDebug()<<"Successfully sumited to the worklist table.";
        }
        else
        {
            qDebug()<<"Failed to submit to the worklist table. Due to: "<<_model2->lastError().text();;
        }


    //_database.close();


}

void MainWindow::on_action_Quick_Start_triggered()
{
    ExposureDialog* _dialog =new ExposureDialog(this);
    //_dialog->show();
    _dialog->showMaximized();

}

void MainWindow::on_action_Update_PACS_Server_Settings_triggered()
{
   PacsNodeSettingsDialog* _dialog = new PacsNodeSettingsDialog(this);
   _dialog->show();

}

void MainWindow::on_action_Load_Study_triggered()
{

    LoadStudyDialog* _dialog=new LoadStudyDialog(this);
    _dialog->show();
}

void MainWindow::on_action_Update_Worklist_Settings_triggered()
{
    WorklistServerSettingsDialog* worklistDlg =new WorklistServerSettingsDialog(this);
    worklistDlg->show();
}

void MainWindow::on_action_Open_Study_triggered()
{    
    wrkDlg->show();
}

void MainWindow::on_Patient_selected(QSqlRecord record)
{

//    for(int i=0;i<record.count();i++)
//    {
//        qDebug()<<"the "<<record.fieldName(i) <<" fields value is "<<record.field(i).value().toString();
//    }

    ExposureDialog* _dialog =new ExposureDialog(this);
    _dialog->SetRecord(&record);
    _dialog->show();
}

void MainWindow::on_Login_Successfully()
{
    //Check the database for the loged in user
    // the password is hashed.
    qDebug()<<"The pass:"<<loginDlg->GetPassword();
    QString _name= loginDlg->GetUsername();
    QString _pass= loginDlg->GetPassword();

    QSqlDatabase  _database = QSqlDatabase::addDatabase("QSQLITE");
    _database.setDatabaseName("./database/database.db");
    if (!_database.open())
    {
        qDebug() << "Failed to open the database";
        return ;
    }
    else
    {
        qDebug()<<"Database connection is made...";
    }


    QSqlQuery query;
    bool flag=false;
    if(query.exec("SELECT * FROM userTbl"))
    {
        qDebug()<<"Query is executed";

        // the users found
        while(query.next())
        {
            qDebug()<<"User ID:"<<query.value(0).toString();
            qDebug()<<"User Name:"<<query.value(1).toString()<<_name;
            qDebug()<<"User Password:"<<query.value(2).toString()<<_pass;

            if(query.value(1).toString() == _name &&
               query.value(2).toString() == _pass)
            {
                qDebug()<<"success";
                flag=true;
                break;
            }
        }
    }
    if(flag== false)
    {
        loginDlg->exec();
    }

    //_database.close();


}

void MainWindow::on_Login_Failed()
{

    loginDlg->show();
}
