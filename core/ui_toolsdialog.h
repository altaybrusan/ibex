/********************************************************************************
** Form generated from reading UI file 'toolsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSDIALOG_H
#define UI_TOOLSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QFrame *credentialsFrame;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *userLbl;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *userLineEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwordLbl;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *passwordLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *retypePasswordLbl;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *retypePasswordlineEdit;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addUserBtn;
    QPushButton *removeUserBtn;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *manufacturerLbl;
    QLineEdit *manufacturerLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *institutionNameLbl;
    QLineEdit *institutionNameLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *stationNameLbl;
    QLineEdit *stationNameLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *manufacturerModelNameLbl;
    QLineEdit *manufacturerModelNameLineEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ToolsDialog)
    {
        if (ToolsDialog->objectName().isEmpty())
            ToolsDialog->setObjectName(QStringLiteral("ToolsDialog"));
        ToolsDialog->resize(692, 531);
        verticalLayout = new QVBoxLayout(ToolsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(ToolsDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        credentialsFrame = new QFrame(tab);
        credentialsFrame->setObjectName(QStringLiteral("credentialsFrame"));
        credentialsFrame->setFrameShape(QFrame::StyledPanel);
        credentialsFrame->setFrameShadow(QFrame::Sunken);
        verticalLayout_4 = new QVBoxLayout(credentialsFrame);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        userLbl = new QLabel(credentialsFrame);
        userLbl->setObjectName(QStringLiteral("userLbl"));

        horizontalLayout->addWidget(userLbl);

        horizontalSpacer_3 = new QSpacerItem(38, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        userLineEdit = new QLineEdit(credentialsFrame);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));

        horizontalLayout->addWidget(userLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        passwordLbl = new QLabel(credentialsFrame);
        passwordLbl->setObjectName(QStringLiteral("passwordLbl"));

        horizontalLayout_2->addWidget(passwordLbl);

        horizontalSpacer_6 = new QSpacerItem(2, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        passwordLineEdit = new QLineEdit(credentialsFrame);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(passwordLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        retypePasswordLbl = new QLabel(credentialsFrame);
        retypePasswordLbl->setObjectName(QStringLiteral("retypePasswordLbl"));

        horizontalLayout_3->addWidget(retypePasswordLbl);

        horizontalSpacer_5 = new QSpacerItem(22, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        retypePasswordlineEdit = new QLineEdit(credentialsFrame);
        retypePasswordlineEdit->setObjectName(QStringLiteral("retypePasswordlineEdit"));
        retypePasswordlineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(retypePasswordlineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addUserBtn = new QPushButton(credentialsFrame);
        addUserBtn->setObjectName(QStringLiteral("addUserBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addUserBtn->sizePolicy().hasHeightForWidth());
        addUserBtn->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/assets/images/_48_add_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        addUserBtn->setIcon(icon);

        verticalLayout_3->addWidget(addUserBtn);

        removeUserBtn = new QPushButton(credentialsFrame);
        removeUserBtn->setObjectName(QStringLiteral("removeUserBtn"));
        sizePolicy.setHeightForWidth(removeUserBtn->sizePolicy().hasHeightForWidth());
        removeUserBtn->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/assets/images/_48_remove_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeUserBtn->setIcon(icon1);

        verticalLayout_3->addWidget(removeUserBtn);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_6->addWidget(credentialsFrame);

        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        manufacturerLbl = new QLabel(frame);
        manufacturerLbl->setObjectName(QStringLiteral("manufacturerLbl"));

        horizontalLayout_5->addWidget(manufacturerLbl);

        manufacturerLineEdit = new QLineEdit(frame);
        manufacturerLineEdit->setObjectName(QStringLiteral("manufacturerLineEdit"));

        horizontalLayout_5->addWidget(manufacturerLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        institutionNameLbl = new QLabel(frame);
        institutionNameLbl->setObjectName(QStringLiteral("institutionNameLbl"));

        horizontalLayout_6->addWidget(institutionNameLbl);

        institutionNameLineEdit = new QLineEdit(frame);
        institutionNameLineEdit->setObjectName(QStringLiteral("institutionNameLineEdit"));

        horizontalLayout_6->addWidget(institutionNameLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        stationNameLbl = new QLabel(frame);
        stationNameLbl->setObjectName(QStringLiteral("stationNameLbl"));

        horizontalLayout_7->addWidget(stationNameLbl);

        stationNameLineEdit = new QLineEdit(frame);
        stationNameLineEdit->setObjectName(QStringLiteral("stationNameLineEdit"));

        horizontalLayout_7->addWidget(stationNameLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        manufacturerModelNameLbl = new QLabel(frame);
        manufacturerModelNameLbl->setObjectName(QStringLiteral("manufacturerModelNameLbl"));

        horizontalLayout_8->addWidget(manufacturerModelNameLbl);

        manufacturerModelNameLineEdit = new QLineEdit(frame);
        manufacturerModelNameLineEdit->setObjectName(QStringLiteral("manufacturerModelNameLineEdit"));

        horizontalLayout_8->addWidget(manufacturerModelNameLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout_6->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 148, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(ToolsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ToolsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ToolsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ToolsDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ToolsDialog);
    } // setupUi

    void retranslateUi(QDialog *ToolsDialog)
    {
        ToolsDialog->setWindowTitle(QApplication::translate("ToolsDialog", "Tools", Q_NULLPTR));
        userLbl->setText(QApplication::translate("ToolsDialog", "User", Q_NULLPTR));
        passwordLbl->setText(QApplication::translate("ToolsDialog", "Password", Q_NULLPTR));
        retypePasswordLbl->setText(QApplication::translate("ToolsDialog", "Retype", Q_NULLPTR));
        addUserBtn->setText(QApplication::translate("ToolsDialog", "Add", Q_NULLPTR));
        removeUserBtn->setText(QApplication::translate("ToolsDialog", "Remove", Q_NULLPTR));
        manufacturerLbl->setText(QApplication::translate("ToolsDialog", "Manufacturer", Q_NULLPTR));
        institutionNameLbl->setText(QApplication::translate("ToolsDialog", "Institution Name", Q_NULLPTR));
        stationNameLbl->setText(QApplication::translate("ToolsDialog", "Station Name", Q_NULLPTR));
        manufacturerModelNameLbl->setText(QApplication::translate("ToolsDialog", "Manufacturers Model Name", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ToolsDialog", "System", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ToolsDialog: public Ui_ToolsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSDIALOG_H
