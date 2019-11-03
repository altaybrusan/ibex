/********************************************************************************
** Form generated from reading UI file 'filtersdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERSDIALOG_H
#define UI_FILTERSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FiltersDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *mainTabWidget;
    QWidget *filterTab;
    QVBoxLayout *verticalLayout_2;
    QListWidget *filtersListWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FiltersDialog)
    {
        if (FiltersDialog->objectName().isEmpty())
            FiltersDialog->setObjectName(QStringLiteral("FiltersDialog"));
        FiltersDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(FiltersDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mainTabWidget = new QTabWidget(FiltersDialog);
        mainTabWidget->setObjectName(QStringLiteral("mainTabWidget"));
        filterTab = new QWidget();
        filterTab->setObjectName(QStringLiteral("filterTab"));
        verticalLayout_2 = new QVBoxLayout(filterTab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        filtersListWidget = new QListWidget(filterTab);
        filtersListWidget->setObjectName(QStringLiteral("filtersListWidget"));

        verticalLayout_2->addWidget(filtersListWidget);

        mainTabWidget->addTab(filterTab, QString());

        verticalLayout->addWidget(mainTabWidget);

        buttonBox = new QDialogButtonBox(FiltersDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(FiltersDialog);

        mainTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FiltersDialog);
    } // setupUi

    void retranslateUi(QDialog *FiltersDialog)
    {
        FiltersDialog->setWindowTitle(QApplication::translate("FiltersDialog", "Dialog", Q_NULLPTR));
        mainTabWidget->setTabText(mainTabWidget->indexOf(filterTab), QApplication::translate("FiltersDialog", "Filters", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FiltersDialog: public Ui_FiltersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERSDIALOG_H
