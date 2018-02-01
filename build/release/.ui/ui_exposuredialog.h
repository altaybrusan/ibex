/********************************************************************************
** Form generated from reading UI file 'exposuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPOSUREDIALOG_H
#define UI_EXPOSUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include "ctkCollapsibleGroupBox.h"

QT_BEGIN_NAMESPACE

class Ui_ExposureDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *displayFrame;
    QVBoxLayout *verticalLayout;
    QFrame *sideFrame;
    ctkCollapsibleGroupBox *CollapsibleGroupBox;
    ctkCollapsibleGroupBox *CollapsibleGroupBox_2;
    ctkCollapsibleGroupBox *CollapsibleGroupBox_3;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *line;

    void setupUi(QDialog *ExposureDialog)
    {
        if (ExposureDialog->objectName().isEmpty())
            ExposureDialog->setObjectName(QStringLiteral("ExposureDialog"));
        ExposureDialog->resize(1282, 876);
        horizontalLayout = new QHBoxLayout(ExposureDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        displayFrame = new QFrame(ExposureDialog);
        displayFrame->setObjectName(QStringLiteral("displayFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(displayFrame->sizePolicy().hasHeightForWidth());
        displayFrame->setSizePolicy(sizePolicy);
        displayFrame->setFrameShape(QFrame::Panel);
        displayFrame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(displayFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout->addWidget(displayFrame);

        sideFrame = new QFrame(ExposureDialog);
        sideFrame->setObjectName(QStringLiteral("sideFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sideFrame->sizePolicy().hasHeightForWidth());
        sideFrame->setSizePolicy(sizePolicy1);
        sideFrame->setFrameShape(QFrame::Panel);
        sideFrame->setFrameShadow(QFrame::Plain);
        CollapsibleGroupBox = new ctkCollapsibleGroupBox(sideFrame);
        CollapsibleGroupBox->setObjectName(QStringLiteral("CollapsibleGroupBox"));
        CollapsibleGroupBox->setGeometry(QRect(10, 50, 300, 100));
        CollapsibleGroupBox_2 = new ctkCollapsibleGroupBox(sideFrame);
        CollapsibleGroupBox_2->setObjectName(QStringLiteral("CollapsibleGroupBox_2"));
        CollapsibleGroupBox_2->setGeometry(QRect(10, 200, 300, 100));
        CollapsibleGroupBox_3 = new ctkCollapsibleGroupBox(sideFrame);
        CollapsibleGroupBox_3->setObjectName(QStringLiteral("CollapsibleGroupBox_3"));
        CollapsibleGroupBox_3->setGeometry(QRect(10, 340, 300, 100));
        frame = new QFrame(sideFrame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 490, 231, 80));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(sideFrame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(50, 650, 120, 80));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        line = new QFrame(sideFrame);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 470, 241, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sideFrame);


        retranslateUi(ExposureDialog);

        QMetaObject::connectSlotsByName(ExposureDialog);
    } // setupUi

    void retranslateUi(QDialog *ExposureDialog)
    {
        ExposureDialog->setWindowTitle(QApplication::translate("ExposureDialog", "Dialog", Q_NULLPTR));
        CollapsibleGroupBox->setTitle(QApplication::translate("ExposureDialog", "GroupBox", Q_NULLPTR));
        CollapsibleGroupBox_2->setTitle(QApplication::translate("ExposureDialog", "GroupBox", Q_NULLPTR));
        CollapsibleGroupBox_3->setTitle(QApplication::translate("ExposureDialog", "GroupBox", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExposureDialog: public Ui_ExposureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPOSUREDIALOG_H
