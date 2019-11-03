/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *logoFrame;
    QLabel *infoLbl;
    QLabel *licanseLbl;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(600, 371);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutDialog->sizePolicy().hasHeightForWidth());
        AboutDialog->setSizePolicy(sizePolicy);
        AboutDialog->setMinimumSize(QSize(600, 350));
        AboutDialog->setMaximumSize(QSize(800, 450));
        verticalLayout = new QVBoxLayout(AboutDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logoFrame = new QFrame(AboutDialog);
        logoFrame->setObjectName(QStringLiteral("logoFrame"));
        sizePolicy.setHeightForWidth(logoFrame->sizePolicy().hasHeightForWidth());
        logoFrame->setSizePolicy(sizePolicy);
        logoFrame->setMinimumSize(QSize(86, 86));
        logoFrame->setMaximumSize(QSize(86, 86));
        logoFrame->setStyleSheet(QStringLiteral("image: url(:/assets/images/_ibex_logo.png);"));
        logoFrame->setFrameShape(QFrame::StyledPanel);
        logoFrame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(logoFrame);

        infoLbl = new QLabel(AboutDialog);
        infoLbl->setObjectName(QStringLiteral("infoLbl"));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(11);
        infoLbl->setFont(font);
        infoLbl->setWordWrap(true);

        horizontalLayout->addWidget(infoLbl);


        verticalLayout->addLayout(horizontalLayout);

        licanseLbl = new QLabel(AboutDialog);
        licanseLbl->setObjectName(QStringLiteral("licanseLbl"));
        licanseLbl->setWordWrap(true);

        verticalLayout->addWidget(licanseLbl);

        buttonBox = new QDialogButtonBox(AboutDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AboutDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Dialog", Q_NULLPTR));
        infoLbl->setText(QApplication::translate("AboutDialog", "iBEX\n"
"version 0.1\n"
"Joint project by Durmaz Teknoloji and Bogazici University\n"
"DnE: Altay Brusan", Q_NULLPTR));
        licanseLbl->setText(QApplication::translate("AboutDialog", "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
