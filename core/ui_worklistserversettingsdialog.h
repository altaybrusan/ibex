/********************************************************************************
** Form generated from reading UI file 'worklistserversettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKLISTSERVERSETTINGSDIALOG_H
#define UI_WORKLISTSERVERSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WorklistServerSettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *ipAddressLbl;
    QLineEdit *ipAddresslineEdit;
    QLabel *portLbl;
    QLineEdit *portLineEdit;
    QLabel *AETitleLbl;
    QLineEdit *AETitleLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WorklistServerSettingsDialog)
    {
        if (WorklistServerSettingsDialog->objectName().isEmpty())
            WorklistServerSettingsDialog->setObjectName(QStringLiteral("WorklistServerSettingsDialog"));
        WorklistServerSettingsDialog->resize(425, 171);
        verticalLayout = new QVBoxLayout(WorklistServerSettingsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(WorklistServerSettingsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        ipAddressLbl = new QLabel(groupBox);
        ipAddressLbl->setObjectName(QStringLiteral("ipAddressLbl"));

        formLayout->setWidget(0, QFormLayout::LabelRole, ipAddressLbl);

        ipAddresslineEdit = new QLineEdit(groupBox);
        ipAddresslineEdit->setObjectName(QStringLiteral("ipAddresslineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ipAddresslineEdit);

        portLbl = new QLabel(groupBox);
        portLbl->setObjectName(QStringLiteral("portLbl"));

        formLayout->setWidget(1, QFormLayout::LabelRole, portLbl);

        portLineEdit = new QLineEdit(groupBox);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, portLineEdit);

        AETitleLbl = new QLabel(groupBox);
        AETitleLbl->setObjectName(QStringLiteral("AETitleLbl"));

        formLayout->setWidget(2, QFormLayout::LabelRole, AETitleLbl);

        AETitleLineEdit = new QLineEdit(groupBox);
        AETitleLineEdit->setObjectName(QStringLiteral("AETitleLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, AETitleLineEdit);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(WorklistServerSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(WorklistServerSettingsDialog);

        QMetaObject::connectSlotsByName(WorklistServerSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *WorklistServerSettingsDialog)
    {
        WorklistServerSettingsDialog->setWindowTitle(QApplication::translate("WorklistServerSettingsDialog", "RIS Server", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("WorklistServerSettingsDialog", "RIS System", Q_NULLPTR));
        ipAddressLbl->setText(QApplication::translate("WorklistServerSettingsDialog", "IP Address", Q_NULLPTR));
        portLbl->setText(QApplication::translate("WorklistServerSettingsDialog", "Remote Port", Q_NULLPTR));
        AETitleLbl->setText(QApplication::translate("WorklistServerSettingsDialog", "AE Title", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WorklistServerSettingsDialog: public Ui_WorklistServerSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKLISTSERVERSETTINGSDIALOG_H
