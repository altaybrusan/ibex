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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoadImageDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *displayFrame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *controlFrame;
    QVBoxLayout *verticalLayout;
    QPushButton *openBtn;

    void setupUi(QDialog *LoadImageDialog)
    {
        if (LoadImageDialog->objectName().isEmpty())
            LoadImageDialog->setObjectName(QStringLiteral("LoadImageDialog"));
        LoadImageDialog->resize(1400, 750);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoadImageDialog->sizePolicy().hasHeightForWidth());
        LoadImageDialog->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(LoadImageDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        displayFrame = new QFrame(LoadImageDialog);
        displayFrame->setObjectName(QStringLiteral("displayFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(4);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(displayFrame->sizePolicy().hasHeightForWidth());
        displayFrame->setSizePolicy(sizePolicy1);
        displayFrame->setFrameShape(QFrame::Panel);
        displayFrame->setFrameShadow(QFrame::Plain);
        horizontalLayout_2 = new QHBoxLayout(displayFrame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        horizontalLayout->addWidget(displayFrame);

        controlFrame = new QFrame(LoadImageDialog);
        controlFrame->setObjectName(QStringLiteral("controlFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(controlFrame->sizePolicy().hasHeightForWidth());
        controlFrame->setSizePolicy(sizePolicy2);
        controlFrame->setFrameShape(QFrame::Panel);
        controlFrame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(controlFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        openBtn = new QPushButton(controlFrame);
        openBtn->setObjectName(QStringLiteral("openBtn"));
        openBtn->setMinimumSize(QSize(0, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/assets/images/_48_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openBtn->setIcon(icon);

        verticalLayout->addWidget(openBtn);


        horizontalLayout->addWidget(controlFrame);


        retranslateUi(LoadImageDialog);

        QMetaObject::connectSlotsByName(LoadImageDialog);
    } // setupUi

    void retranslateUi(QDialog *LoadImageDialog)
    {
        LoadImageDialog->setWindowTitle(QApplication::translate("LoadImageDialog", "load file dialog", Q_NULLPTR));
        openBtn->setText(QApplication::translate("LoadImageDialog", "open", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadImageDialog: public Ui_LoadImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADIMAGEDIALOG_H
