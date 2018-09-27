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
#include "logindialog.h"


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

    _dialog= new NewPatientDialog(this);
    connect(_dialog,SIGNAL(accepted()),this,SLOT(on_newPatient_accepted()));
    connect(wrkDlg,SIGNAL(NotifyRecoredSelected(QSqlRecord)),this,SLOT(on_Patient_selected(QSqlRecord)));
    connect(loginDlg,SIGNAL(accepted()),this,SLOT(on_Login_Successfully()));
    connect(loginDlg,SIGNAL(rejected()),this,SLOT(on_Login_Failed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_Study_triggered()
{

    _dialog->setModal(true);
    _dialog->show();

}

void MainWindow::on_newPatient_accepted()
{
    qDebug()<< "Dialog RESULT:"<<_dialog->result();
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



}

void MainWindow::on_Login_Failed()
{

    loginDlg->show();
}
