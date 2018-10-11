/********************************************************************************
** Form generated from reading UI file 'pacssettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACSSETTINGSDIALOG_H
#define UI_PACSSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PacsSettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PacsSettingsDialog)
    {
        if (PacsSettingsDialog->objectName().isEmpty())
            PacsSettingsDialog->setObjectName(QStringLiteral("PacsSettingsDialog"));
        PacsSettingsDialog->resize(800, 500);
        verticalLayout = new QVBoxLayout(PacsSettingsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(PacsSettingsDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(PacsSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PacsSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PacsSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PacsSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PacsSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *PacsSettingsDialog)
    {
        PacsSettingsDialog->setWindowTitle(QApplication::translate("PacsSettingsDialog", "PACS Server Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PacsSettingsDialog: public Ui_PacsSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACSSETTINGSDIALOG_H
