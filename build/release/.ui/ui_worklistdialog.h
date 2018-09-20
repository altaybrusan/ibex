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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_WorkListDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *leftFrame;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QFrame *rightFrame;
    QPushButton *reloadBtn;

    void setupUi(QDialog *WorkListDialog)
    {
        if (WorkListDialog->objectName().isEmpty())
            WorkListDialog->setObjectName(QStringLiteral("WorkListDialog"));
        WorkListDialog->resize(623, 332);
        horizontalLayout = new QHBoxLayout(WorkListDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leftFrame = new QFrame(WorkListDialog);
        leftFrame->setObjectName(QStringLiteral("leftFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftFrame->sizePolicy().hasHeightForWidth());
        leftFrame->setSizePolicy(sizePolicy);
        leftFrame->setFrameShape(QFrame::StyledPanel);
        leftFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(leftFrame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView = new QTableView(leftFrame);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout_2->addWidget(tableView);


        horizontalLayout->addWidget(leftFrame);

        rightFrame = new QFrame(WorkListDialog);
        rightFrame->setObjectName(QStringLiteral("rightFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rightFrame->sizePolicy().hasHeightForWidth());
        rightFrame->setSizePolicy(sizePolicy1);
        rightFrame->setFrameShape(QFrame::StyledPanel);
        rightFrame->setFrameShadow(QFrame::Raised);
        reloadBtn = new QPushButton(rightFrame);
        reloadBtn->setObjectName(QStringLiteral("reloadBtn"));
        reloadBtn->setGeometry(QRect(20, 20, 80, 31));

        horizontalLayout->addWidget(rightFrame);


        retranslateUi(WorkListDialog);

        QMetaObject::connectSlotsByName(WorkListDialog);
    } // setupUi

    void retranslateUi(QDialog *WorkListDialog)
    {
        WorkListDialog->setWindowTitle(QApplication::translate("WorkListDialog", "Dialog", Q_NULLPTR));
        reloadBtn->setText(QApplication::translate("WorkListDialog", "Reload", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WorkListDialog: public Ui_WorkListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKLISTDIALOG_H
