#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPluginLoader>
#include "iforegroundtool.h"

#include"newpatientdialog.h"


namespace StartupTool
{
    MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

    QStringList MainWindow::RipMenuPath(QString menuPath)
    {
        return menuPath.split("/");
    }

    void MainWindow::loadPlugins()
    {
        //foreach (QObject *plugin, QPluginLoader::staticInstances())
            //populateMenus(plugin);

        pluginsDir = QDir(qApp->applicationDirPath());

    #if defined(Q_OS_WIN)
        if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
        {
            pluginsDir.cdUp();
            pluginsDir.cdUp();
        }
    #elif defined(Q_OS_MAC)
        if (pluginsDir.dirName() == "MacOS") {
            pluginsDir.cdUp();
            pluginsDir.cdUp();
            pluginsDir.cdUp();
        }
    #endif
        pluginsDir.cd("plugins");

        qDebug()<< "The path is: "<<pluginsDir;
        foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
            QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
            QObject *plugin = loader.instance();
            if (plugin) {
                //populateMenus(plugin);
                pluginFileNames += fileName;
            }
        }
//        brushMenu->setEnabled(!brushActionGroup->actions().isEmpty());
//        shapesMenu->setEnabled(!shapesMenu->actions().isEmpty());
//        filterMenu->setEnabled(!filterMenu->actions().isEmpty());

    }


    void MainWindow::on_action_New_Examination_triggered()
    {
        NewPatientDialog _dialog;
        _dialog.show();
        _dialog.exec();
    }
    void MainWindow::on_action_Open_Local_Examination_triggered()
    {


    }
    void MainWindow::on_action_Load_From_Worklist_triggered()
    {
    }
    void MainWindow::on_action_Print_triggered()
    {

    }
    void MainWindow::on_action_Write_to_CD_DVD_triggered()
    {

    }
    void MainWindow::on_action_Exit_Application_triggered()
    {
        // This is demo. For next iteration we have to check all other windows
        // and send signals to all Tools before closing.
        QApplication::quit();

    }


    void MainWindow::on_action_Connections_Settings_triggered()
    {

    }
    void MainWindow::on_action_Devices_Settings_triggered()
    {

    }
    void MainWindow::on_action_Worklist_Settings_triggered()
    {

    }
    void MainWindow::on_action_PACS_Server_Settings_triggered()
    {

    }


    void MainWindow::on_action_Peripherals_System_triggered()
    {

    }
    void MainWindow::on_action_Filters_System_triggered()
    {

    }
    void MainWindow::on_action_Tools_System_triggered()
    {

    }


    void MainWindow::on_action_About_Help_triggered()
    {

    }




}




