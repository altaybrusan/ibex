/********************************************************************************
** Form generated from reading UI file 'pacsnodesettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACSNODESETTINGSDIALOG_H
#define UI_PACSNODESETTINGSDIALOG_H

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

class Ui_PacsNodeSettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PacsNodeSettingsDialog)
    {
        if (PacsNodeSettingsDialog->objectName().isEmpty())
            PacsNodeSettingsDialog->setObjectName(QStringLiteral("PacsNodeSettingsDialog"));
        PacsNodeSettingsDialog->resize(800, 500);
        verticalLayout = new QVBoxLayout(PacsNodeSettingsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(PacsNodeSettingsDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        buttonBox = new QDialogButtonBox(PacsNodeSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PacsNodeSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PacsNodeSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PacsNodeSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PacsNodeSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *PacsNodeSettingsDialog)
    {
        PacsNodeSettingsDialog->setWindowTitle(QApplication::translate("PacsNodeSettingsDialog", "PACS Server Settings", Q_NULLPTR));
    } // retranslateUi

};

namespPacsSettingsDialogsNodeSettingsDialog: public Ui_PacsNodeSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACSNODESETTINGSDIALOG_H
