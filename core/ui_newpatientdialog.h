/********************************************************************************
** Form generated from reading UI file 'newpatientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPATIENTDIALOG_H
#define UI_NEWPATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewPatientDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_title;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_8;
    QFrame *frame_3;
    QLabel *titleLbl;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_12;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lastNameLbl;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lastNameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *firstNameLbl;
    QSpacerItem *horizontalSpacer;
    QLineEdit *firstNameLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *middleNameLbl;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *middleNameLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *patientIDLbl;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *patientIdLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *birthDateLbl;
    QSpacerItem *horizontalSpacer_10;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *GenderLbl;
    QSpacerItem *horizontalSpacer_11;
    QComboBox *genderComboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *refessingPhysicianLbl;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *referringPhysicianLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *admissionNumberLbl;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *admissionNumberLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *accessionNumberLbl;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *accessionNumberLineEdit;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_11;
    QLabel *viewLbl;
    QSpacerItem *horizontalSpacer_12;
    QComboBox *viewComboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewPatientDialog)
    {
        if (NewPatientDialog->objectName().isEmpty())
            NewPatientDialog->setObjectName(QStringLiteral("NewPatientDialog"));
        NewPatientDialog->resize(676, 514);
        NewPatientDialog->setStyleSheet(QStringLiteral("background-color: rgb(172, 172, 172);"));
        verticalLayout_4 = new QVBoxLayout(NewPatientDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        frame_title = new QFrame(NewPatientDialog);
        frame_title->setObjectName(QStringLiteral("frame_title"));
        frame_title->setFrameShape(QFrame::Box);
        frame_title->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame_title);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);

        frame_3 = new QFrame(frame_title);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(48, 48));
        frame_3->setMaximumSize(QSize(48, 48));
        frame_3->setStyleSheet(QStringLiteral("background-image: url(:/assets/images/_48_start_document.png);"));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Plain);

        horizontalLayout_10->addWidget(frame_3);

        titleLbl = new QLabel(frame_title);
        titleLbl->setObjectName(QStringLiteral("titleLbl"));
        titleLbl->setStyleSheet(QStringLiteral("font: 75 22pt \"Bell MT\";"));

        horizontalLayout_10->addWidget(titleLbl);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_10);


        verticalLayout_4->addWidget(frame_title);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        frame = new QFrame(NewPatientDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lastNameLbl = new QLabel(frame);
        lastNameLbl->setObjectName(QStringLiteral("lastNameLbl"));

        horizontalLayout->addWidget(lastNameLbl);

        horizontalSpacer_2 = new QSpacerItem(37, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lastNameLineEdit = new QLineEdit(frame);
        lastNameLineEdit->setObjectName(QStringLiteral("lastNameLineEdit"));
        lastNameLineEdit->setStyleSheet(QLatin1String("font: 75 14pt \"Times New Roman\";\n"
"background-color: rgb(255, 255, 255);\n"
""));

        horizontalLayout->addWidget(lastNameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        firstNameLbl = new QLabel(frame);
        firstNameLbl->setObjectName(QStringLiteral("firstNameLbl"));

        horizontalLayout_2->addWidget(firstNameLbl);

        horizontalSpacer = new QSpacerItem(46, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        firstNameLineEdit = new QLineEdit(frame);
        firstNameLineEdit->setObjectName(QStringLiteral("firstNameLineEdit"));
        firstNameLineEdit->setStyleSheet(QLatin1String("font: 75 14pt \"Times New Roman\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(firstNameLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        middleNameLbl = new QLabel(frame);
        middleNameLbl->setObjectName(QStringLiteral("middleNameLbl"));

        horizontalLayout_3->addWidget(middleNameLbl);

        horizontalSpacer_3 = new QSpacerItem(26, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        middleNameLineEdit = new QLineEdit(frame);
        middleNameLineEdit->setObjectName(QStringLiteral("middleNameLineEdit"));
        middleNameLineEdit->setStyleSheet(QLatin1String("font: 75 14pt \"Times New Roman\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(middleNameLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        patientIDLbl = new QLabel(frame);
        patientIDLbl->setObjectName(QStringLiteral("patientIDLbl"));

        horizontalLayout_4->addWidget(patientIDLbl);

        horizontalSpacer_4 = new QSpacerItem(41, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        patientIdLineEdit = new QLineEdit(frame);
        patientIdLineEdit->setObjectName(QStringLiteral("patientIdLineEdit"));
        patientIdLineEdit->setStyleSheet(QLatin1String("font: 75 14pt \"Times New Roman\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(patientIdLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        birthDateLbl = new QLabel(frame);
        birthDateLbl->setObjectName(QStringLiteral("birthDateLbl"));

        horizontalLayout_5->addWidget(birthDateLbl);

        horizontalSpacer_10 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);

        dateEdit = new QDateEdit(frame);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy);
        dateEdit->setStyleSheet(QStringLiteral("font: 75 14pt \"Times New Roman\";"));

        horizontalLayout_5->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        GenderLbl = new QLabel(frame);
        GenderLbl->setObjectName(QStringLiteral("GenderLbl"));

        horizontalLayout_6->addWidget(GenderLbl);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        genderComboBox = new QComboBox(frame);
        genderComboBox->setObjectName(QStringLiteral("genderComboBox"));
        genderComboBox->setStyleSheet(QLatin1String("font: 75 14pt \"Times New Roman\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_6->addWidget(genderComboBox);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        refessingPhysicianLbl = new QLabel(frame);
        refessingPhysicianLbl->setObjectName(QStringLiteral("refessingPhysicianLbl"));

        horizontalLayout_7->addWidget(refessingPhysicianLbl);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        referringPhysicianLineEdit = new QLineEdit(frame);
        referringPhysicianLineEdit->setObjectName(QStringLiteral("referringPhysicianLineEdit"));
        referringPhysicianLineEdit->setStyleSheet(QLatin1String("font: 75 14pt \"Times New Roman\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(referringPhysicianLineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        admissionNumberLbl = new QLabel(frame);
        admissionNumberLbl->setObjectName(QStringLiteral("admissionNumberLbl"));

        horizontalLayout_8->addWidget(admissionNumberLbl);

        horizontalSpacer_6 = new QSpacerItem(42, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        admissionNumberLineEdit = new QLineEdit(frame);
        admissionNumberLineEdit->setObjectName(QStringLiteral("admissionNumberLineEdit"));
        admissionNumberLineEdit->setStyleSheet(QLatin1String("font: 75 14pt \"Times New Roman\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_8->addWidget(admissionNumberLineEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        accessionNumberLbl = new QLabel(frame);
        accessionNumberLbl->setObjectName(QStringLiteral("accessionNumberLbl"));

        horizontalLayout_9->addWidget(accessionNumberLbl);

        horizontalSpacer_7 = new QSpacerItem(34, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        accessionNumberLineEdit = new QLineEdit(frame);
        accessionNumberLineEdit->setObjectName(QStringLiteral("accessionNumberLineEdit"));
        accessionNumberLineEdit->setStyleSheet(QLatin1String("font: 75 14pt \"Times New Roman\";\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_9->addWidget(accessionNumberLineEdit);


        verticalLayout->addLayout(horizontalLayout_9);


        horizontalLayout_12->addWidget(frame);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        graphicsView = new QGraphicsView(NewPatientDialog);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(180, 380));
        graphicsView->setMaximumSize(QSize(180, 380));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(graphicsView);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        viewLbl = new QLabel(NewPatientDialog);
        viewLbl->setObjectName(QStringLiteral("viewLbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(viewLbl->sizePolicy().hasHeightForWidth());
        viewLbl->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(viewLbl);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_12);

        viewComboBox = new QComboBox(NewPatientDialog);
        viewComboBox->setObjectName(QStringLiteral("viewComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(viewComboBox->sizePolicy().hasHeightForWidth());
        viewComboBox->setSizePolicy(sizePolicy2);

        horizontalLayout_11->addWidget(viewComboBox);


        verticalLayout_2->addLayout(horizontalLayout_11);


        horizontalLayout_12->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_12);

        buttonBox = new QDialogButtonBox(NewPatientDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        lastNameLbl->setBuddy(lastNameLineEdit);
        firstNameLbl->setBuddy(firstNameLineEdit);
        middleNameLbl->setBuddy(middleNameLineEdit);
        patientIDLbl->setBuddy(patientIdLineEdit);
        birthDateLbl->setBuddy(dateEdit);
        GenderLbl->setBuddy(genderComboBox);
        refessingPhysicianLbl->setBuddy(referringPhysicianLineEdit);
        admissionNumberLbl->setBuddy(admissionNumberLineEdit);
        accessionNumberLbl->setBuddy(accessionNumberLineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lastNameLineEdit, firstNameLineEdit);
        QWidget::setTabOrder(firstNameLineEdit, middleNameLineEdit);
        QWidget::setTabOrder(middleNameLineEdit, patientIdLineEdit);
        QWidget::setTabOrder(patientIdLineEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, genderComboBox);
        QWidget::setTabOrder(genderComboBox, referringPhysicianLineEdit);
        QWidget::setTabOrder(referringPhysicianLineEdit, admissionNumberLineEdit);
        QWidget::setTabOrder(admissionNumberLineEdit, accessionNumberLineEdit);

        retranslateUi(NewPatientDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewPatientDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewPatientDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewPatientDialog);
    } // setupUi

    void retranslateUi(QDialog *NewPatientDialog)
    {
        NewPatientDialog->setWindowTitle(QApplication::translate("NewPatientDialog", "New Patient Registeration", Q_NULLPTR));
        titleLbl->setText(QApplication::translate("NewPatientDialog", "Patient Information", Q_NULLPTR));
        lastNameLbl->setText(QApplication::translate("NewPatientDialog", "&Last Name*", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        lastNameLineEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lastNameLineEdit->setWhatsThis(QApplication::translate("NewPatientDialog", "patient last name", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        firstNameLbl->setText(QApplication::translate("NewPatientDialog", "&First Name", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        firstNameLineEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        firstNameLineEdit->setWhatsThis(QApplication::translate("NewPatientDialog", "patient first name", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        middleNameLbl->setText(QApplication::translate("NewPatientDialog", "&Middle Name", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        middleNameLineEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        middleNameLineEdit->setWhatsThis(QApplication::translate("NewPatientDialog", "patient middle name", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        patientIDLbl->setText(QApplication::translate("NewPatientDialog", "&Patient ID*", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        patientIdLineEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        patientIdLineEdit->setWhatsThis(QApplication::translate("NewPatientDialog", "Primary hospital identification number or code for the patient. Tag(0010,0020)", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        birthDateLbl->setText(QApplication::translate("NewPatientDialog", "&Birth Date", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        dateEdit->setWhatsThis(QApplication::translate("NewPatientDialog", "patient birthdate", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        GenderLbl->setText(QApplication::translate("NewPatientDialog", "&Gender", Q_NULLPTR));
        genderComboBox->setCurrentText(QString());
        refessingPhysicianLbl->setText(QApplication::translate("NewPatientDialog", "&Referring Physician", Q_NULLPTR));
        admissionNumberLbl->setText(QApplication::translate("NewPatientDialog", "&Admission Number", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        admissionNumberLineEdit->setWhatsThis(QApplication::translate("NewPatientDialog", "Identification number of the visit as assigned by the healthcare provider. Tag (0038,0010)", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        accessionNumberLbl->setText(QApplication::translate("NewPatientDialog", "A&ccession Number*", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        accessionNumberLineEdit->setWhatsThis(QApplication::translate("NewPatientDialog", "A RIS generated number that identifies the order for the Study. Tag (0008,0050)", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        viewLbl->setText(QApplication::translate("NewPatientDialog", "View", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewPatientDialog: public Ui_NewPatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPATIENTDIALOG_H
