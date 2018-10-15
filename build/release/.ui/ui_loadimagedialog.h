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
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_LoadImageDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QVTKWidget *qvtkWidget;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QPushButton *loadBtn;

    void setupUi(QDialog *LoadImageDialog)
    {
        if (LoadImageDialog->objectName().isEmpty())
            LoadImageDialog->setObjectName(QStringLiteral("LoadImageDialog"));
        LoadImageDialog->resize(800, 750);
        horizontalLayout = new QHBoxLayout(LoadImageDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(LoadImageDialog);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        qvtkWidget = new QVTKWidget(frame);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));

        horizontalLayout_2->addWidget(qvtkWidget);


        horizontalLayout->addWidget(frame);

        frame_2 = new QFrame(LoadImageDialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        loadBtn = new QPushButton(frame_2);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));
        loadBtn->setMinimumSize(QSize(0, 25));

        formLayout->setWidget(0, QFormLayout::LabelRole, loadBtn);


        horizontalLayout->addWidget(frame_2);


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
