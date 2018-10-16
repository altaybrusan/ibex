/********************************************************************************
** Form generated from reading UI file 'imageviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QAction *actionvFlip;
    QAction *actionhFlip;
    QAction *actioninvertColor;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *mainFrame;
    QVBoxLayout *verticalLayout;
    QFrame *displayFrame;
    QVBoxLayout *verticalLayout_2;
    QVTKWidget *qvtkWidget;
    QFrame *settingFrame;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QFrame *line;
    QFrame *thumbnailFrame;
    QFrame *line_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QSpacerItem *verticalSpacer;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QStringLiteral("ImageViewer"));
        ImageViewer->resize(973, 608);
        actionvFlip = new QAction(ImageViewer);
        actionvFlip->setObjectName(QStringLiteral("actionvFlip"));
        actionvFlip->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/assets/images/_48_vertical_flip.png"), QSize(), QIcon::Normal, QIcon::On);
        actionvFlip->setIcon(icon);
        actionhFlip = new QAction(ImageViewer);
        actionhFlip->setObjectName(QStringLiteral("actionhFlip"));
        actionhFlip->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/assets/images/_48_horizontal_flip.png"), QSize(), QIcon::Normal, QIcon::On);
        actionhFlip->setIcon(icon1);
        actioninvertColor = new QAction(ImageViewer);
        actioninvertColor->setObjectName(QStringLiteral("actioninvertColor"));
        actioninvertColor->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/assets/images/_48_invert_selection.png"), QSize(), QIcon::Normal, QIcon::On);
        actioninvertColor->setIcon(icon2);
        centralwidget = new QWidget(ImageViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mainFrame = new QFrame(centralwidget);
        mainFrame->setObjectName(QStringLiteral("mainFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(5);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainFrame->sizePolicy().hasHeightForWidth());
        mainFrame->setSizePolicy(sizePolicy);
        mainFrame->setFrameShape(QFrame::Panel);
        mainFrame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(mainFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        displayFrame = new QFrame(mainFrame);
        displayFrame->setObjectName(QStringLiteral("displayFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(displayFrame->sizePolicy().hasHeightForWidth());
        displayFrame->setSizePolicy(sizePolicy1);
        displayFrame->setFrameShape(QFrame::StyledPanel);
        displayFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(displayFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        qvtkWidget = new QVTKWidget(displayFrame);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));

        verticalLayout_2->addWidget(qvtkWidget);


        verticalLayout->addWidget(displayFrame);


        horizontalLayout->addWidget(mainFrame);

        settingFrame = new QFrame(centralwidget);
        settingFrame->setObjectName(QStringLiteral("settingFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(settingFrame->sizePolicy().hasHeightForWidth());
        settingFrame->setSizePolicy(sizePolicy2);
        settingFrame->setFrameShape(QFrame::Panel);
        settingFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_5 = new QVBoxLayout(settingFrame);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);

        verticalLayout_5->addLayout(verticalLayout_3);

        line = new QFrame(settingFrame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        thumbnailFrame = new QFrame(settingFrame);
        thumbnailFrame->setObjectName(QStringLiteral("thumbnailFrame"));
        thumbnailFrame->setMinimumSize(QSize(0, 70));
        thumbnailFrame->setMaximumSize(QSize(16777215, 150));
        thumbnailFrame->setFrameShape(QFrame::Box);
        thumbnailFrame->setFrameShadow(QFrame::Plain);

        verticalLayout_5->addWidget(thumbnailFrame);

        line_2 = new QFrame(settingFrame);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        scrollArea = new QScrollArea(settingFrame);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::Panel);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 257, 226));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout->addWidget(settingFrame);

        ImageViewer->setCentralWidget(centralwidget);
        toolBar = new QToolBar(ImageViewer);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        ImageViewer->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionvFlip);
        toolBar->addAction(actionhFlip);
        toolBar->addAction(actioninvertColor);

        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewer)
    {
        ImageViewer->setWindowTitle(QApplication::translate("ImageViewer", "MainWindow", Q_NULLPTR));
        actionvFlip->setText(QApplication::translate("ImageViewer", "vFlip", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionvFlip->setToolTip(QApplication::translate("ImageViewer", "vertical flip", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionhFlip->setText(QApplication::translate("ImageViewer", "hFlip", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionhFlip->setToolTip(QApplication::translate("ImageViewer", "horizontal flip", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actioninvertColor->setText(QApplication::translate("ImageViewer", "invertColor", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actioninvertColor->setToolTip(QApplication::translate("ImageViewer", "invert color", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        qvtkWidget->setToolTip(QApplication::translate("ImageViewer", "press r to reset window & level. press shift + r to reset camera.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("ImageViewer", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
