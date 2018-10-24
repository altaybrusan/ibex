#include "View/loadstudydialog.h"
#include "ui_loadstudydialog.h"
#include <Utils/logmgr.h>
#include <ctkDICOMDatabase.h>

LoadStudyDialog::LoadStudyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadStudyDialog)
{
    ui->setupUi(this);
    connect(ui->queryRetrieve,&ctkDICOMQueryRetrieveWidget::canceled,this,[=](){
           emit NotifyLoadStudyDialogIsClosing();
    });

}

void LoadStudyDialog::UpdateRetrieveDatabase(QSharedPointer<ctkDICOMDatabase> dbPointer)
{
    ui->queryRetrieve->setRetrieveDatabase(dbPointer);
}

LoadStudyDialog::~LoadStudyDialog()
{
    delete ui;
}


