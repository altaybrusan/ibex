#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpatientdialog.h"
#include "QMessageBox"
#include "worklistserversettingsdialog.h"
#include "worklistdialog.h"
#include <QSqlField>
#include <QDesktopWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "logindialog.h"
#include <QDateTime>
#include "Utils/logmgr.h"
#include "View/loadImagedialog.h"
#include "View/aboutdialog.h"
int MACHINE_UID=001;


MainWindow::MainWindow(QWidget *parent, LoadImageDialog &loadImageDialog) :
    QMainWindow(parent),
    m_loadImageDlg(loadImageDialog),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
     //_model->submitAll();
    delete ui;
}



void MainWindow::showEvent(QShowEvent *event)
{
    QWidget::showEvent( event );
    emit NotifyMainWindowIsLoaded();
}

//void MainWindow::on_Patient_selected(QSqlRecord record)
//{

//////    for(int i=0;i<record.count();i++)
//////    {
//////        qDebug()<<"the "<<record.fieldName(i) <<" fields value is "<<record.field(i).value().toString();
//////    }

////    ExposureDialog* _dialog =new ExposureDialog(this);
////    _dialog->SetRecord(&record);
////    _dialog->show();
//}

void MainWindow::on_action_Update_PACS_Server_Settings_triggered()
{
    LogMgr::instance()->LogSysDebug(tr("loading pacs server is triggered."));
    emit NotifyUpdatePACSSettingIsTriggered();
}

void MainWindow::on_action_Update_Worklist_Settings_triggered()
{
    LogMgr::instance()->LogSysDebug(tr("worklist settings is triggered"));
    emit NotifyUpdateWorklistSettingsIsTriggered();

}

void MainWindow::on_action_Load_Study_triggered()
{
    emit NotifyLoadStudyIsTriggered();
}

void MainWindow::on_action_Open_Study_triggered()
{
    // This is not best practice: a view class initiates another
    // view objet. however, because for this iteration we know
    // that the LoadImageDialog is a simple object with
    // no controller associated. We ignore the MVC pattern
    // however, for the future iteration we can make more
    // suffisticated dialogs and turn it inot MVC design
    //LogMgr::instance()->LogSysDebug(tr("open study is triggered"));
    //LoadImageDialog* _demo=new LoadImageDialog(this);
    //_demo->show();
    m_loadImageDlg.repaint();
    m_loadImageDlg.Show();
}

void MainWindow::on_action_Quick_Start_triggered()
{
    emit NotifyQuickStudyWorkFlowIsTriggered();

}

void MainWindow::on_action_Select_triggered()
{
    emit NotifyWorklistLoadIsTriggered();
}

void MainWindow::on_action_New_Study_triggered()
{
    emit NotifyNewStudyWorkFlowIsTriggered();
}

AboutDialog* _dialog;
void MainWindow::on_action_About_triggered()
{
    _dialog =new AboutDialog(this);
    _dialog->setModal(true);
    _dialog->setWindowTitle("About iBEX");
    _dialog->show();
}
