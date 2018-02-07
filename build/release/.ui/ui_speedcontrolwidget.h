/********************************************************************************
** Form generated from reading UI file 'speedcontrolwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPEEDCONTROLWIDGET_H
#define UI_SPEEDCONTROLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ctkSliderWidget.h"

QT_BEGIN_NAMESPACE

class Ui_speedControlWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *motorJogLbl;
    ctkSliderWidget *speedSlider;
    QHBoxLayout *horizontalLayout;
    QToolButton *moveBackwardBtn;
    QSpacerItem *horizontalSpacer;
    QToolButton *stopBtn;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *moveForwardBtn;

    void setupUi(QWidget *speedControlWidget)
    {
        if (speedControlWidget->objectName().isEmpty())
            speedControlWidget->setObjectName(QStringLiteral("speedControlWidget"));
        speedControlWidget->resize(340, 155);
        verticalLayout_2 = new QVBoxLayout(speedControlWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        motorJogLbl = new QLabel(speedControlWidget);
        motorJogLbl->setObjectName(QStringLiteral("motorJogLbl"));

        verticalLayout->addWidget(motorJogLbl);

        speedSlider = new ctkSliderWidget(speedControlWidget);
        speedSlider->setObjectName(QStringLiteral("speedSlider"));

        verticalLayout->addWidget(speedSlider);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        moveBackwardBtn = new QToolButton(speedControlWidget);
        moveBackwardBtn->setObjectName(QStringLiteral("moveBackwardBtn"));
        moveBackwardBtn->setMinimumSize(QSize(100, 100));
        moveBackwardBtn->setMaximumSize(QSize(100, 100));
        moveBackwardBtn->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 127);"));
        moveBackwardBtn->setIconSize(QSize(64, 64));
        moveBackwardBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(moveBackwardBtn);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stopBtn = new QToolButton(speedControlWidget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setMinimumSize(QSize(100, 100));
        stopBtn->setMaximumSize(QSize(100, 100));
        QFont font;
        font.setFamily(QStringLiteral("Tahoma"));
        stopBtn->setFont(font);
        stopBtn->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 127);"));
        stopBtn->setIconSize(QSize(64, 64));
        stopBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(stopBtn);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        moveForwardBtn = new QToolButton(speedControlWidget);
        moveForwardBtn->setObjectName(QStringLiteral("moveForwardBtn"));
        moveForwardBtn->setMinimumSize(QSize(100, 100));
        moveForwardBtn->setMaximumSize(QSize(100, 100));
        moveForwardBtn->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 127);"));
        moveForwardBtn->setIconSize(QSize(64, 64));
        moveForwardBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(moveForwardBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(speedControlWidget);

        QMetaObject::connectSlotsByName(speedControlWidget);
    } // setupUi

    void retranslateUi(QWidget *speedControlWidget)
    {
        speedControlWidget->setWindowTitle(QApplication::translate("speedControlWidget", "Form", Q_NULLPTR));
        motorJogLbl->setText(QApplication::translate("speedControlWidget", "Motor JOG [R/min]", Q_NULLPTR));
        moveBackwardBtn->setText(QApplication::translate("speedControlWidget", "Backward", Q_NULLPTR));
        stopBtn->setText(QApplication::translate("speedControlWidget", "Stop", Q_NULLPTR));
        moveForwardBtn->setText(QApplication::translate("speedControlWidget", "Forward", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class speedControlWidget: public Ui_speedControlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPEEDCONTROLWIDGET_H
