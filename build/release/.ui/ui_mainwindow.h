/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New_Study;
    QAction *action_Open_Study;
    QAction *action_Load_Study;
    QAction *action_Quick_Start;
    QAction *action_Print_Study;
    QAction *action_Write_To_CD;
    QAction *action_Exit;
    QAction *action_Get_Peripherals_Status;
    QAction *action_Get_Tools_Status;
    QAction *action_Get_Filters_Status;
    QAction *action_Get_Connections;
    QAction *action_Update_Devices_Settings;
    QAction *action_Update_Worklist_Settings;
    QAction *action_Update_PACS_Server_Settings;
    QAction *action_About;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *mainMenuBar;
    QMenu *menuStudy;
    QMenu *menuS_ystem;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QToolBar *studyToolBar;
    QStatusBar *statusBar;
    QToolBar *systemToolBar;
    QToolBar *settingsToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1291, 710);
        QIcon icon;
        icon.addFile(QStringLiteral(":/assets/images/_ibex_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(172, 172, 172);\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"\n"
""));
        action_New_Study = new QAction(MainWindow);
        action_New_Study->setObjectName(QStringLiteral("action_New_Study"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/assets/images/_48_start_document.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_New_Study->setIcon(icon1);
        action_Open_Study = new QAction(MainWindow);
        action_Open_Study->setObjectName(QStringLiteral("action_Open_Study"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/assets/images/_48_open_document.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Open_Study->setIcon(icon2);
        action_Load_Study = new QAction(MainWindow);
        action_Load_Study->setObjectName(QStringLiteral("action_Load_Study"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/assets/images/_48_load.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Load_Study->setIcon(icon3);
        action_Quick_Start = new QAction(MainWindow);
        action_Quick_Start->setObjectName(QStringLiteral("action_Quick_Start"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/assets/images/_48_quick.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Quick_Start->setIcon(icon4);
        action_Print_Study = new QAction(MainWindow);
        action_Print_Study->setObjectName(QStringLiteral("action_Print_Study"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/assets/images/_48_printing.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Print_Study->setIcon(icon5);
        action_Write_To_CD = new QAction(MainWindow);
        action_Write_To_CD->setObjectName(QStringLiteral("action_Write_To_CD"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/assets/images/_48_writecd.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Write_To_CD->setIcon(icon6);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/assets/images/_48_exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon7);
        action_Get_Peripherals_Status = new QAction(MainWindow);
        action_Get_Peripherals_Status->setObjectName(QStringLiteral("action_Get_Peripherals_Status"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/assets/images/_48_pheripherals.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Get_Peripherals_Status->setIcon(icon8);
        action_Get_Tools_Status = new QAction(MainWindow);
        action_Get_Tools_Status->setObjectName(QStringLiteral("action_Get_Tools_Status"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/assets/images/_48_tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Get_Tools_Status->setIcon(icon9);
        action_Get_Filters_Status = new QAction(MainWindow);
        action_Get_Filters_Status->setObjectName(QStringLiteral("action_Get_Filters_Status"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/assets/images/_48_filters.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Get_Filters_Status->setIcon(icon10);
        action_Get_Connections = new QAction(MainWindow);
        action_Get_Connections->setObjectName(QStringLiteral("action_Get_Connections"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/assets/images/_48_connections.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Get_Connections->setIcon(icon11);
        action_Update_Devices_Settings = new QAction(MainWindow);
        action_Update_Devices_Settings->setObjectName(QStringLiteral("action_Update_Devices_Settings"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/assets/images/_48_devices.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Update_Devices_Settings->setIcon(icon12);
        action_Update_Worklist_Settings = new QAction(MainWindow);
        action_Update_Worklist_Settings->setObjectName(QStringLiteral("action_Update_Worklist_Settings"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/assets/images/_48_worklist.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Update_Worklist_Settings->setIcon(icon13);
        action_Update_PACS_Server_Settings = new QAction(MainWindow);
        action_Update_PACS_Server_Settings->setObjectName(QStringLiteral("action_Update_PACS_Server_Settings"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/assets/images/_48_pacs_server.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Update_PACS_Server_Settings->setIcon(icon14);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/assets/images/_48_info.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_About->setIcon(icon15);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(100, 100));
        frame->setMaximumSize(QSize(100, 100));
        frame->setStyleSheet(QStringLiteral("border-image: url(:/assets/images/_ibex_logo.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        mainMenuBar = new QMenuBar(MainWindow);
        mainMenuBar->setObjectName(QStringLiteral("mainMenuBar"));
        mainMenuBar->setGeometry(QRect(0, 0, 1291, 26));
        mainMenuBar->setStyleSheet(QLatin1String("background-color: rgb(0, 170, 127);\n"
"border-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(85, 170, 255);\n"
""));
        menuStudy = new QMenu(mainMenuBar);
        menuStudy->setObjectName(QStringLiteral("menuStudy"));
        menuS_ystem = new QMenu(mainMenuBar);
        menuS_ystem->setObjectName(QStringLiteral("menuS_ystem"));
        menuSettings = new QMenu(mainMenuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuHelp = new QMenu(mainMenuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(mainMenuBar);
        studyToolBar = new QToolBar(MainWindow);
        studyToolBar->setObjectName(QStringLiteral("studyToolBar"));
        studyToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, studyToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        systemToolBar = new QToolBar(MainWindow);
        systemToolBar->setObjectName(QStringLiteral("systemToolBar"));
        systemToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, systemToolBar);
        settingsToolBar = new QToolBar(MainWindow);
        settingsToolBar->setObjectName(QStringLiteral("settingsToolBar"));
        settingsToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, settingsToolBar);

        mainMenuBar->addAction(menuStudy->menuAction());
        mainMenuBar->addAction(menuS_ystem->menuAction());
        mainMenuBar->addAction(menuSettings->menuAction());
        mainMenuBar->addAction(menuHelp->menuAction());
        menuStudy->addAction(action_New_Study);
        menuStudy->addAction(action_Open_Study);
        menuStudy->addAction(action_Load_Study);
        menuStudy->addAction(action_Quick_Start);
        menuStudy->addSeparator();
        menuStudy->addAction(action_Print_Study);
        menuStudy->addAction(action_Write_To_CD);
        menuStudy->addSeparator();
        menuStudy->addAction(action_Exit);
        menuS_ystem->addAction(action_Get_Peripherals_Status);
        menuS_ystem->addAction(action_Get_Tools_Status);
        menuS_ystem->addAction(action_Get_Filters_Status);
        menuSettings->addAction(action_Get_Connections);
        menuSettings->addAction(action_Update_Devices_Settings);
        menuSettings->addAction(action_Update_Worklist_Settings);
        menuSettings->addAction(action_Update_PACS_Server_Settings);
        menuHelp->addAction(action_About);
        studyToolBar->addAction(action_New_Study);
        studyToolBar->addAction(action_Open_Study);
        studyToolBar->addAction(action_Load_Study);
        studyToolBar->addAction(action_Quick_Start);
        studyToolBar->addSeparator();
        studyToolBar->addAction(action_Print_Study);
        studyToolBar->addAction(action_Write_To_CD);
        systemToolBar->addAction(action_Get_Peripherals_Status);
        systemToolBar->addAction(action_Get_Tools_Status);
        systemToolBar->addAction(action_Get_Filters_Status);
        settingsToolBar->addAction(action_Get_Connections);
        settingsToolBar->addAction(action_Update_Devices_Settings);
        settingsToolBar->addAction(action_Update_Worklist_Settings);
        settingsToolBar->addAction(action_Update_PACS_Server_Settings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "iBEX", Q_NULLPTR));
        action_New_Study->setText(QApplication::translate("MainWindow", "&New", Q_NULLPTR));
        action_Open_Study->setText(QApplication::translate("MainWindow", "&Open", Q_NULLPTR));
        action_Load_Study->setText(QApplication::translate("MainWindow", "&Load", Q_NULLPTR));
        action_Quick_Start->setText(QApplication::translate("MainWindow", "&Quick", Q_NULLPTR));
        action_Print_Study->setText(QApplication::translate("MainWindow", "Print", Q_NULLPTR));
        action_Write_To_CD->setText(QApplication::translate("MainWindow", "Write", Q_NULLPTR));
        action_Exit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        action_Get_Peripherals_Status->setText(QApplication::translate("MainWindow", "Peripherals", Q_NULLPTR));
        action_Get_Tools_Status->setText(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        action_Get_Filters_Status->setText(QApplication::translate("MainWindow", "Filters", Q_NULLPTR));
        action_Get_Connections->setText(QApplication::translate("MainWindow", "Connections", Q_NULLPTR));
        action_Update_Devices_Settings->setText(QApplication::translate("MainWindow", "Devices", Q_NULLPTR));
        action_Update_Worklist_Settings->setText(QApplication::translate("MainWindow", "Worklist", Q_NULLPTR));
        action_Update_PACS_Server_Settings->setText(QApplication::translate("MainWindow", "PACS Server", Q_NULLPTR));
        action_About->setText(QApplication::translate("MainWindow", "&About", Q_NULLPTR));
        menuStudy->setTitle(QApplication::translate("MainWindow", "&Study", Q_NULLPTR));
        menuS_ystem->setTitle(QApplication::translate("MainWindow", "S&ystem", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
        systemToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        settingsToolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
