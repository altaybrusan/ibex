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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ctkCollapsibleGroupBox.h"

QT_BEGIN_NAMESPACE

class Ui_ExposureDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *displayFrame;
    QVBoxLayout *verticalLayout;
    QFrame *sideFrame;
    QVBoxLayout *verticalLayout_2;
    QFrame *titleFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *iconhorizontalSpacerLeft;
    QFrame *frame;
    QSpacerItem *iconhorizontalSpacerRight;
    ctkCollapsibleGroupBox *patientDemographyBox;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QLabel *nameLbl;
    QLineEdit *fullNameLineEdit;
    QLabel *addmissionNumberLbl;
    QLineEdit *accessionNumLineEdit;
    QLabel *label_5;
    QLineEdit *dobLineEdit;
    QLabel *sexLbl;
    QLineEdit *sexLineEdit;
    QTableView *procedureTableView;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *statusFrame;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser;

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
        sizePolicy.setHorizontalStretch(4);
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
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sideFrame->sizePolicy().hasHeightForWidth());
        sideFrame->setSizePolicy(sizePolicy1);
        sideFrame->setFrameShape(QFrame::Panel);
        sideFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(sideFrame);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        titleFrame = new QFrame(sideFrame);
        titleFrame->setObjectName(QStringLiteral("titleFrame"));
        titleFrame->setMaximumSize(QSize(16777215, 80));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(titleFrame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 3, -1, 3);
        iconhorizontalSpacerLeft = new QSpacerItem(90, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(iconhorizontalSpacerLeft);

        frame = new QFrame(titleFrame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 70));
        frame->setStyleSheet(QStringLiteral("image: url(:/assets/images/_72_radiation_sign.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame);

        iconhorizontalSpacerRight = new QSpacerItem(90, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(iconhorizontalSpacerRight);


        verticalLayout_2->addWidget(titleFrame);

        patientDemographyBox = new ctkCollapsibleGroupBox(sideFrame);
        patientDemographyBox->setObjectName(QStringLiteral("patientDemographyBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(patientDemographyBox->sizePolicy().hasHeightForWidth());
        patientDemographyBox->setSizePolicy(sizePolicy2);
        horizontalLayout_3 = new QHBoxLayout(patientDemographyBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        frame_2 = new QFrame(patientDemographyBox);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        nameLbl = new QLabel(frame_2);
        nameLbl->setObjectName(QStringLiteral("nameLbl"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLbl);

        fullNameLineEdit = new QLineEdit(frame_2);
        fullNameLineEdit->setObjectName(QStringLiteral("fullNameLineEdit"));
        fullNameLineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, fullNameLineEdit);

        addmissionNumberLbl = new QLabel(frame_2);
        addmissionNumberLbl->setObjectName(QStringLiteral("addmissionNumberLbl"));

        formLayout->setWidget(1, QFormLayout::LabelRole, addmissionNumberLbl);

        accessionNumLineEdit = new QLineEdit(frame_2);
        accessionNumLineEdit->setObjectName(QStringLiteral("accessionNumLineEdit"));
        accessionNumLineEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, accessionNumLineEdit);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        dobLineEdit = new QLineEdit(frame_2);
        dobLineEdit->setObjectName(QStringLiteral("dobLineEdit"));
        dobLineEdit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, dobLineEdit);

        sexLbl = new QLabel(frame_2);
        sexLbl->setObjectName(QStringLiteral("sexLbl"));

        formLayout->setWidget(3, QFormLayout::LabelRole, sexLbl);

        sexLineEdit = new QLineEdit(frame_2);
        sexLineEdit->setObjectName(QStringLiteral("sexLineEdit"));
        sexLineEdit->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, sexLineEdit);


        horizontalLayout_3->addWidget(frame_2);


        verticalLayout_2->addWidget(patientDemographyBox);

        procedureTableView = new QTableView(sideFrame);
        procedureTableView->setObjectName(QStringLiteral("procedureTableView"));
        procedureTableView->setMaximumSize(QSize(16777215, 150));

        verticalLayout_2->addWidget(procedureTableView);

        line = new QFrame(sideFrame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        scrollArea = new QScrollArea(sideFrame);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 250));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 410, 214));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        statusFrame = new QFrame(sideFrame);
        statusFrame->setObjectName(QStringLiteral("statusFrame"));
        statusFrame->setMaximumSize(QSize(16777215, 160));
        statusFrame->setFrameShape(QFrame::Panel);
        statusFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_3 = new QVBoxLayout(statusFrame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        textBrowser = new QTextBrowser(statusFrame);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMaximumSize(QSize(16777215, 150));
        textBrowser->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));

        verticalLayout_3->addWidget(textBrowser);


        verticalLayout_2->addWidget(statusFrame);


        horizontalLayout->addWidget(sideFrame);


        retranslateUi(ExposureDialog);

        QMetaObject::connectSlotsByName(ExposureDialog);
    } // setupUi

    void retranslateUi(QDialog *ExposureDialog)
    {
        ExposureDialog->setWindowTitle(QApplication::translate("ExposureDialog", "Exposure Dialog", Q_NULLPTR));
        patientDemographyBox->setTitle(QApplication::translate("ExposureDialog", "Patients Demography", Q_NULLPTR));
        nameLbl->setText(QApplication::translate("ExposureDialog", "Full name:", Q_NULLPTR));
        addmissionNumberLbl->setText(QApplication::translate("ExposureDialog", "Accession", Q_NULLPTR));
        label_5->setText(QApplication::translate("ExposureDialog", "Birth date:", Q_NULLPTR));
        sexLbl->setText(QApplication::translate("ExposureDialog", "Sex", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExposureDialog: public Ui_ExposureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPOSUREDIALOG_H
