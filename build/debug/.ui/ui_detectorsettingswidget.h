/********************************************************************************
** Form generated from reading UI file 'detectorsettingswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTORSETTINGSWIDGET_H
#define UI_DETECTORSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectorSettingsWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *parametersFrame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *binningLbl;
    QComboBox *binningComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lineSpeedLbl;
    QSpinBox *lineSpeedSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *imageHeightLbl;
    QSpinBox *imageHeightSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *modeLbl;
    QComboBox *modeComboBox;
    QFrame *commandsframe;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *grabBtn;

    void setupUi(QWidget *DetectorSettingsWidget)
    {
        if (DetectorSettingsWidget->objectName().isEmpty())
            DetectorSettingsWidget->setObjectName(QStringLiteral("DetectorSettingsWidget"));
        DetectorSettingsWidget->resize(326, 338);
        verticalLayout_2 = new QVBoxLayout(DetectorSettingsWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        parametersFrame = new QFrame(DetectorSettingsWidget);
        parametersFrame->setObjectName(QStringLiteral("parametersFrame"));
        parametersFrame->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        parametersFrame->setFrameShape(QFrame::StyledPanel);
        parametersFrame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(parametersFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        binningLbl = new QLabel(parametersFrame);
        binningLbl->setObjectName(QStringLiteral("binningLbl"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        binningLbl->setFont(font);

        horizontalLayout->addWidget(binningLbl);

        binningComboBox = new QComboBox(parametersFrame);
        binningComboBox->setObjectName(QStringLiteral("binningComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(binningComboBox->sizePolicy().hasHeightForWidth());
        binningComboBox->setSizePolicy(sizePolicy);
        binningComboBox->setFont(font);

        horizontalLayout->addWidget(binningComboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineSpeedLbl = new QLabel(parametersFrame);
        lineSpeedLbl->setObjectName(QStringLiteral("lineSpeedLbl"));
        lineSpeedLbl->setFont(font);

        horizontalLayout_2->addWidget(lineSpeedLbl);

        lineSpeedSpinBox = new QSpinBox(parametersFrame);
        lineSpeedSpinBox->setObjectName(QStringLiteral("lineSpeedSpinBox"));
        sizePolicy.setHeightForWidth(lineSpeedSpinBox->sizePolicy().hasHeightForWidth());
        lineSpeedSpinBox->setSizePolicy(sizePolicy);
        lineSpeedSpinBox->setFont(font);
        lineSpeedSpinBox->setMinimum(50);
        lineSpeedSpinBox->setMaximum(2000);

        horizontalLayout_2->addWidget(lineSpeedSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        imageHeightLbl = new QLabel(parametersFrame);
        imageHeightLbl->setObjectName(QStringLiteral("imageHeightLbl"));
        imageHeightLbl->setFont(font);

        horizontalLayout_3->addWidget(imageHeightLbl);

        imageHeightSpinBox = new QSpinBox(parametersFrame);
        imageHeightSpinBox->setObjectName(QStringLiteral("imageHeightSpinBox"));
        sizePolicy.setHeightForWidth(imageHeightSpinBox->sizePolicy().hasHeightForWidth());
        imageHeightSpinBox->setSizePolicy(sizePolicy);
        imageHeightSpinBox->setFont(font);
        imageHeightSpinBox->setMinimum(25);
        imageHeightSpinBox->setMaximum(16665);

        horizontalLayout_3->addWidget(imageHeightSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        modeLbl = new QLabel(parametersFrame);
        modeLbl->setObjectName(QStringLiteral("modeLbl"));
        modeLbl->setFont(font);

        horizontalLayout_4->addWidget(modeLbl);

        modeComboBox = new QComboBox(parametersFrame);
        modeComboBox->setObjectName(QStringLiteral("modeComboBox"));
        sizePolicy.setHeightForWidth(modeComboBox->sizePolicy().hasHeightForWidth());
        modeComboBox->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Tahoma"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        modeComboBox->setFont(font1);
        modeComboBox->setStyleSheet(QStringLiteral("font: 12pt \"Tahoma\";"));

        horizontalLayout_4->addWidget(modeComboBox);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(parametersFrame);

        commandsframe = new QFrame(DetectorSettingsWidget);
        commandsframe->setObjectName(QStringLiteral("commandsframe"));
        commandsframe->setFrameShape(QFrame::StyledPanel);
        commandsframe->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(commandsframe);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        grabBtn = new QToolButton(commandsframe);
        grabBtn->setObjectName(QStringLiteral("grabBtn"));
        grabBtn->setMinimumSize(QSize(100, 100));
        grabBtn->setMaximumSize(QSize(100, 100));
        grabBtn->setStyleSheet(QLatin1String("font: 8pt \"Tahoma\";\n"
"background-color: rgb(85, 170, 127);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/image/grab.png"), QSize(), QIcon::Normal, QIcon::Off);
        grabBtn->setIcon(icon);
        grabBtn->setIconSize(QSize(64, 64));
        grabBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(grabBtn, 0, 1, 1, 1);


        verticalLayout_2->addWidget(commandsframe);


        retranslateUi(DetectorSettingsWidget);

        QMetaObject::connectSlotsByName(DetectorSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *DetectorSettingsWidget)
    {
        DetectorSettingsWidget->setWindowTitle(QApplication::translate("DetectorSettingsWidget", "Form", Q_NULLPTR));
        binningLbl->setText(QApplication::translate("DetectorSettingsWidget", "Binning", Q_NULLPTR));
        binningComboBox->clear();
        binningComboBox->insertItems(0, QStringList()
         << QApplication::translate("DetectorSettingsWidget", "2x2", Q_NULLPTR)
         << QApplication::translate("DetectorSettingsWidget", "3x3", Q_NULLPTR)
         << QApplication::translate("DetectorSettingsWidget", "4x4", Q_NULLPTR)
         << QApplication::translate("DetectorSettingsWidget", "5x5", Q_NULLPTR)
         << QApplication::translate("DetectorSettingsWidget", "6x6", Q_NULLPTR)
        );
        lineSpeedLbl->setText(QApplication::translate("DetectorSettingsWidget", "Line Speed [Hz]", Q_NULLPTR));
        imageHeightLbl->setText(QApplication::translate("DetectorSettingsWidget", "Image Height", Q_NULLPTR));
        modeLbl->setText(QApplication::translate("DetectorSettingsWidget", "Mode", Q_NULLPTR));
        modeComboBox->clear();
        modeComboBox->insertItems(0, QStringList()
         << QApplication::translate("DetectorSettingsWidget", "TDI", Q_NULLPTR)
         << QApplication::translate("DetectorSettingsWidget", "Area", Q_NULLPTR)
        );
        grabBtn->setText(QApplication::translate("DetectorSettingsWidget", "Grab", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DetectorSettingsWidget: public Ui_DetectorSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTORSETTINGSWIDGET_H
