/********************************************************************************
** Form generated from reading UI file 'protocoladjustmentwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTOCOLADJUSTMENTWIDGET_H
#define UI_PROTOCOLADJUSTMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ctkSliderWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ProtocolAdjustmentWidget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QFrame *displayFrame;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_1;
    QLabel *kvpLbl;
    ctkSliderWidget *kvpSlider;
    QSpacerItem *horizontalSpacer_1;
    QLCDNumber *kvpLcd;
    QHBoxLayout *horizontalLayout_2;
    QLabel *currentLbl;
    ctkSliderWidget *currentSlider;
    QSpacerItem *horizontalSpacer_2;
    QLCDNumber *currentLcd;
    QHBoxLayout *horizontalLayout_3;
    QLabel *timeLbl;
    ctkSliderWidget *durationSlider;
    QSpacerItem *horizontalSpacer_3;
    QLCDNumber *durationLcd;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QLabel *passedTimeLbl;
    QSpacerItem *horizontalSpacer_4;
    QLCDNumber *passedTimeLcd;
    QVBoxLayout *verticalLayout_2;
    QToolButton *applyBtn;
    QToolButton *toggleFocalSpotBtn;

    void setupUi(QWidget *ProtocolAdjustmentWidget)
    {
        if (ProtocolAdjustmentWidget->objectName().isEmpty())
            ProtocolAdjustmentWidget->setObjectName(QStringLiteral("ProtocolAdjustmentWidget"));
        ProtocolAdjustmentWidget->resize(505, 255);
        horizontalLayout_5 = new QHBoxLayout(ProtocolAdjustmentWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        displayFrame = new QFrame(ProtocolAdjustmentWidget);
        displayFrame->setObjectName(QStringLiteral("displayFrame"));
        displayFrame->setFrameShape(QFrame::StyledPanel);
        displayFrame->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(displayFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QStringLiteral("horizontalLayout_1"));
        kvpLbl = new QLabel(displayFrame);
        kvpLbl->setObjectName(QStringLiteral("kvpLbl"));
        QFont font;
        font.setPointSize(9);
        kvpLbl->setFont(font);

        horizontalLayout_1->addWidget(kvpLbl);

        kvpSlider = new ctkSliderWidget(displayFrame);
        kvpSlider->setObjectName(QStringLiteral("kvpSlider"));

        horizontalLayout_1->addWidget(kvpSlider);

        horizontalSpacer_1 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_1->addItem(horizontalSpacer_1);

        kvpLcd = new QLCDNumber(displayFrame);
        kvpLcd->setObjectName(QStringLiteral("kvpLcd"));
        kvpLcd->setMinimumSize(QSize(0, 30));
        kvpLcd->setStyleSheet(QLatin1String("\n"
"background-color: rgb(0, 0, 0);\n"
"\n"
"color: rgb(0, 255, 0);"));
        kvpLcd->setDigitCount(3);
        kvpLcd->setSegmentStyle(QLCDNumber::Flat);
        kvpLcd->setProperty("value", QVariant(0));

        horizontalLayout_1->addWidget(kvpLcd);


        verticalLayout->addLayout(horizontalLayout_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        currentLbl = new QLabel(displayFrame);
        currentLbl->setObjectName(QStringLiteral("currentLbl"));
        currentLbl->setFont(font);

        horizontalLayout_2->addWidget(currentLbl);

        currentSlider = new ctkSliderWidget(displayFrame);
        currentSlider->setObjectName(QStringLiteral("currentSlider"));

        horizontalLayout_2->addWidget(currentSlider);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        currentLcd = new QLCDNumber(displayFrame);
        currentLcd->setObjectName(QStringLiteral("currentLcd"));
        currentLcd->setMinimumSize(QSize(0, 30));
        currentLcd->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        currentLcd->setDigitCount(3);
        currentLcd->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_2->addWidget(currentLcd);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        timeLbl = new QLabel(displayFrame);
        timeLbl->setObjectName(QStringLiteral("timeLbl"));
        timeLbl->setFont(font);

        horizontalLayout_3->addWidget(timeLbl);

        durationSlider = new ctkSliderWidget(displayFrame);
        durationSlider->setObjectName(QStringLiteral("durationSlider"));
        durationSlider->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(durationSlider);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        durationLcd = new QLCDNumber(displayFrame);
        durationLcd->setObjectName(QStringLiteral("durationLcd"));
        durationLcd->setMinimumSize(QSize(0, 30));
        durationLcd->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        durationLcd->setDigitCount(3);
        durationLcd->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_3->addWidget(durationLcd);


        verticalLayout->addLayout(horizontalLayout_3);

        line = new QFrame(displayFrame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        passedTimeLbl = new QLabel(displayFrame);
        passedTimeLbl->setObjectName(QStringLiteral("passedTimeLbl"));

        horizontalLayout_4->addWidget(passedTimeLbl);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        passedTimeLcd = new QLCDNumber(displayFrame);
        passedTimeLcd->setObjectName(QStringLiteral("passedTimeLcd"));
        passedTimeLcd->setMinimumSize(QSize(0, 30));
        passedTimeLcd->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        passedTimeLcd->setDigitCount(3);
        passedTimeLcd->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_4->addWidget(passedTimeLcd);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        applyBtn = new QToolButton(displayFrame);
        applyBtn->setObjectName(QStringLiteral("applyBtn"));
        applyBtn->setMinimumSize(QSize(100, 100));
        applyBtn->setMaximumSize(QSize(100, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Tahoma"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        applyBtn->setFont(font1);
        applyBtn->setStyleSheet(QLatin1String("font: 9pt \"Tahoma\";\n"
"background-color: rgb(85, 170, 127);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/image/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        applyBtn->setIcon(icon);
        applyBtn->setIconSize(QSize(64, 64));
        applyBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(applyBtn);

        toggleFocalSpotBtn = new QToolButton(displayFrame);
        toggleFocalSpotBtn->setObjectName(QStringLiteral("toggleFocalSpotBtn"));
        toggleFocalSpotBtn->setMinimumSize(QSize(100, 100));
        toggleFocalSpotBtn->setMaximumSize(QSize(100, 100));
        toggleFocalSpotBtn->setStyleSheet(QLatin1String("font: 9pt \"Tahoma\";\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/image/largspot.png"), QSize(), QIcon::Normal, QIcon::Off);
        toggleFocalSpotBtn->setIcon(icon1);
        toggleFocalSpotBtn->setIconSize(QSize(64, 64));
        toggleFocalSpotBtn->setCheckable(true);
        toggleFocalSpotBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        verticalLayout_2->addWidget(toggleFocalSpotBtn);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_5->addWidget(displayFrame);


        retranslateUi(ProtocolAdjustmentWidget);

        QMetaObject::connectSlotsByName(ProtocolAdjustmentWidget);
    } // setupUi

    void retranslateUi(QWidget *ProtocolAdjustmentWidget)
    {
        ProtocolAdjustmentWidget->setWindowTitle(QApplication::translate("ProtocolAdjustmentWidget", "Form", Q_NULLPTR));
        kvpLbl->setText(QApplication::translate("ProtocolAdjustmentWidget", "KVP", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        kvpLcd->setToolTip(QApplication::translate("ProtocolAdjustmentWidget", "Actual applied KVP by the generator", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        currentLbl->setText(QApplication::translate("ProtocolAdjustmentWidget", "Current [mA]", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        currentLcd->setToolTip(QApplication::translate("ProtocolAdjustmentWidget", "Actual amper applied by the generator", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        timeLbl->setText(QApplication::translate("ProtocolAdjustmentWidget", "Duration [dMin]", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        durationLcd->setToolTip(QApplication::translate("ProtocolAdjustmentWidget", "Actual applied exposure duration applied by the generator", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        passedTimeLbl->setText(QApplication::translate("ProtocolAdjustmentWidget", "Passed Time [dMin]", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        passedTimeLcd->setToolTip(QApplication::translate("ProtocolAdjustmentWidget", "Passed exposure time. Shows the value passed from the exposure duration", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        applyBtn->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        applyBtn->setText(QApplication::translate("ProtocolAdjustmentWidget", "Apply", Q_NULLPTR));
        toggleFocalSpotBtn->setText(QApplication::translate("ProtocolAdjustmentWidget", "Focal", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProtocolAdjustmentWidget: public Ui_ProtocolAdjustmentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTOCOLADJUSTMENTWIDGET_H
