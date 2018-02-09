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

QT_BEGIN_NAMESPACE

class Ui_LoadStudyDialog
{
public:

    void setupUi(QDialog *LoadStudyDialog)
    {
        if (LoadStudyDialog->objectName().isEmpty())
            LoadStudyDialog->setObjectName(QStringLiteral("LoadStudyDialog"));
        LoadStudyDialog->resize(471, 373);

        retranslateUi(LoadStudyDialog);

        QMetaObject::connectSlotsByName(LoadStudyDialog);
    } // setupUi

    void retranslateUi(QDialog *LoadStudyDialog)
    {
        LoadStudyDialog->setWindowTitle(QApplication::translate("LoadStudyDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadStudyDialog: public Ui_LoadStudyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADSTUDYDIALOG_H
