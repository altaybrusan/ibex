#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QMainWindow>


namespace Ui {
    class MainWindow;
}
namespace StartupTool
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:

        void on_action_New_Examination_triggered();

        void on_action_Print_triggered();

        void on_action_Connections_Settings_triggered();

        void on_action_About_Help_triggered();

        void on_action_Devices_Settings_triggered();

        void on_action_Write_to_CD_DVD_triggered();

        void on_action_Exit_Application_triggered();

        void on_action_Peripherals_System_triggered();

        void on_action_Filters_System_triggered();

        void on_action_Worklist_Settings_triggered();

        void on_action_PACS_Server_Settings_triggered();

        void on_action_Open_Local_Examination_triggered();

        void on_action_Load_From_Worklist_triggered();

        void on_action_Tools_System_triggered();

    private:
        QStringList RipMenuPath(QString menuPath);
        void loadPlugins();
//        void populateMenus(QObject *plugin);
        QDir pluginsDir;
        QStringList pluginFileNames;
        Ui::MainWindow *ui;
    };

}


#endif // MAINWINDOW_H
