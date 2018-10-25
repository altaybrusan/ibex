/********************************************************************************
** Form generated from reading UI file 'loadstudydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADSTUDYDIALOG_H
#define UI_LOADSTUDYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include "ctkDICOMQueryRetrieveWidget.h"

QT_BEGIN_NAMESPACE

class Ui_LoadStudyDialog
{
public:
    QVBoxLayout *verticalLayout;
    ctkDICOMQueryRetrieveWidget *queryRetrieve;

    void setupUi(QDialog *LoadStudyDialog)
    {
        if (LoadStudyDialog->objectName().isEmpty())
            LoadStudyDialog->setObjectName(QStringLiteral("LoadStudyDialog"));
        LoadStudyDialog->resize(1104, 754);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoadStudyDialog->sizePolicy().hasHeightForWidth());
        LoadStudyDialog->setSizePolicy(sizePolicy);
        LoadStudyDialog->setMinimumSize(QSize(800, 0));
        verticalLayout = new QVBoxLayout(LoadStudyDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        queryRetrieve = new ctkDICOMQueryRetrieveWidget(LoadStudyDialog);
        queryRetrieve->setObjectName(QStringLiteral("queryRetrieve"));

        verticalLayout->addWidget(queryRetrieve);


        retranslateUi(LoadStudyDialog);

        QMetaObject::connectSlotsByName(LoadStudyDialog);
    } // setupUi

    void retranslateUi(QDialog *LoadStudyDialog)
    {
        LoadStudyDialog->setWindowTitle(QApplication::translate("LoadStudyDialog", "Load study", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadStudyDialog: public Ui_LoadStudyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADSTUDYDIALOG_H
