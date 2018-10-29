/********************************************************************************
** Form generated from reading UI file 'butterworthlowpassfilterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTERWORTHLOWPASSFILTERWIDGET_H
#define UI_BUTTERWORTHLOWPASSFILTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ctkDoubleSpinBox.h"

QT_BEGIN_NAMESPACE

class Ui_ButterworthLowPassFilterWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *titleLbl;
    QPushButton *applyBtn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *yCutOffLbl;
    ctkDoubleSpinBox *yCutOffDSBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *xCutOffLbl;
    ctkDoubleSpinBox *xCutOffDSBox;

    void setupUi(QWidget *ButterworthLowPassFilterWidget)
    {
        if (ButterworthLowPassFilterWidget->objectName().isEmpty())
            ButterworthLowPassFilterWidget->setObjectName(QStringLiteral("ButterworthLowPassFilterWidget"));
        ButterworthLowPassFilterWidget->resize(250, 194);
        horizontalLayout = new QHBoxLayout(ButterworthLowPassFilterWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(ButterworthLowPassFilterWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titleLbl = new QLabel(frame);
        titleLbl->setObjectName(QStringLiteral("titleLbl"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleLbl->sizePolicy().hasHeightForWidth());
        titleLbl->setSizePolicy(sizePolicy);
        titleLbl->setMaximumSize(QSize(16777215, 16));
        titleLbl->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(49, 139, 117, 255), stop:1 rgba(255, 255, 255, 255));"));

        verticalLayout->addWidget(titleLbl);

        applyBtn = new QPushButton(frame);
        applyBtn->setObjectName(QStringLiteral("applyBtn"));
        sizePolicy.setHeightForWidth(applyBtn->sizePolicy().hasHeightForWidth());
        applyBtn->setSizePolicy(sizePolicy);
        applyBtn->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(applyBtn);

        verticalSpacer = new QSpacerItem(5, 4, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        yCutOffLbl = new QLabel(frame);
        yCutOffLbl->setObjectName(QStringLiteral("yCutOffLbl"));

        horizontalLayout_3->addWidget(yCutOffLbl);

        yCutOffDSBox = new ctkDoubleSpinBox(frame);
        yCutOffDSBox->setObjectName(QStringLiteral("yCutOffDSBox"));
        yCutOffDSBox->setDecimals(3);
        yCutOffDSBox->setSingleStep(0.01);

        horizontalLayout_3->addWidget(yCutOffDSBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        xCutOffLbl = new QLabel(frame);
        xCutOffLbl->setObjectName(QStringLiteral("xCutOffLbl"));

        horizontalLayout_2->addWidget(xCutOffLbl);

        xCutOffDSBox = new ctkDoubleSpinBox(frame);
        xCutOffDSBox->setObjectName(QStringLiteral("xCutOffDSBox"));
        xCutOffDSBox->setDecimals(3);
        xCutOffDSBox->setSingleStep(0.01);

        horizontalLayout_2->addWidget(xCutOffDSBox);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addWidget(frame);


        retranslateUi(ButterworthLowPassFilterWidget);

        QMetaObject::connectSlotsByName(ButterworthLowPassFilterWidget);
    } // setupUi

    void retranslateUi(QWidget *ButterworthLowPassFilterWidget)
    {
        ButterworthLowPassFilterWidget->setWindowTitle(QApplication::translate("ButterworthLowPassFilterWidget", "Form", Q_NULLPTR));
        titleLbl->setText(QApplication::translate("ButterworthLowPassFilterWidget", "Butter-worth Low Pass Filter ", Q_NULLPTR));
        applyBtn->setText(QApplication::translate("ButterworthLowPassFilterWidget", "Apply Filter", Q_NULLPTR));
        yCutOffLbl->setText(QApplication::translate("ButterworthLowPassFilterWidget", "Y Cut Off", Q_NULLPTR));
        xCutOffLbl->setText(QApplication::translate("ButterworthLowPassFilterWidget", "X Cut Off", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ButterworthLowPassFilterWidget: public Ui_ButterworthLowPassFilterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTERWORTHLOWPASSFILTERWIDGET_H
