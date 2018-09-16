/********************************************************************************
** Form generated from reading UI file 'worklistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKLISTDIALOG_H
#define UI_WORKLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkListDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QFrame *frame_2;

    void setupUi(QDialog *WorkListDialog)
    {
        if (WorkListDialog->objectName().isEmpty())
            WorkListDialog->setObjectName(QStringLiteral("WorkListDialog"));
        WorkListDialog->resize(400, 300);
        horizontalLayout = new QHBoxLayout(WorkListDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(WorkListDialog);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_2->addWidget(listWidget);


        horizontalLayout->addWidget(frame);

        frame_2 = new QFrame(WorkListDialog);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame_2);


        retranslateUi(WorkListDialog);

        QMetaObject::connectSlotsByName(WorkListDialog);
    } // setupUi

    void retranslateUi(QDialog *WorkListDialog)
    {
        WorkListDialog->setWindowTitle(QApplication::translate("WorkListDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WorkListDialog: public Ui_WorkListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKLISTDIALOG_H
