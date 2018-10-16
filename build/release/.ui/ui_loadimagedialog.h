/********************************************************************************
** Form generated from reading UI file 'loadimagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADIMAGEDIALOG_H
#define UI_LOADIMAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoadImageDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *displayFrame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *controlFrame;
    QFormLayout *formLayout;
    QPushButton *loadBtn;

    void setupUi(QDialog *LoadImageDialog)
    {
        if (LoadImageDialog->objectName().isEmpty())
            LoadImageDialog->setObjectName(QStringLiteral("LoadImageDialog"));
        LoadImageDialog->resize(1400, 750);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoadImageDialog->sizePolicy().hasHeightForWidth());
        LoadImageDialog->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(LoadImageDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        displayFrame = new QFrame(LoadImageDialog);
        displayFrame->setObjectName(QStringLiteral("displayFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(4);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(displayFrame->sizePolicy().hasHeightForWidth());
        displayFrame->setSizePolicy(sizePolicy1);
        displayFrame->setFrameShape(QFrame::Panel);
        displayFrame->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(displayFrame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        horizontalLayout->addWidget(displayFrame);

        controlFrame = new QFrame(LoadImageDialog);
        controlFrame->setObjectName(QStringLiteral("controlFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(controlFrame->sizePolicy().hasHeightForWidth());
        controlFrame->setSizePolicy(sizePolicy2);
        controlFrame->setFrameShape(QFrame::Panel);
        controlFrame->setFrameShadow(QFrame::Plain);
        formLayout = new QFormLayout(controlFrame);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        loadBtn = new QPushButton(controlFrame);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));
        loadBtn->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(0, QFormLayout::LabelRole, loadBtn);


        horizontalLayout->addWidget(controlFrame);


        retranslateUi(LoadImageDialog);

        QMetaObject::connectSlotsByName(LoadImageDialog);
    } // setupUi

    void retranslateUi(QDialog *LoadImageDialog)
    {
        LoadImageDialog->setWindowTitle(QApplication::translate("LoadImageDialog", "load file dialog", Q_NULLPTR));
        loadBtn->setText(QApplication::translate("LoadImageDialog", "Load", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadImageDialog: public Ui_LoadImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADIMAGEDIALOG_H
