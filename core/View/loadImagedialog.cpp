#include "loadImagedialog.h"
#include "ui_loadimagedialog.h"
#include "Utils/logmgr.h"
#include <vtkCamera.h>
#include <QTimer>
#include <ctkFileDialog.h>
#include <QMessageBox>
#include <vtkImageData.h>
#include "View/imageviewer.h"

LoadImageDialog::LoadImageDialog(QWidget *parent, ImageViewer &viewer) :
    QDialog(parent),    
    m_viewer(viewer),
    ui(new Ui::LoadImageDialog)
{
    ui->setupUi(this);

}

void LoadImageDialog::Show()
{
    m_viewer.ClearImageViewer();
    ui->displayFrame->layout()->addWidget(&m_viewer);
    this->show();

}

LoadImageDialog::~LoadImageDialog()
{
    delete ui;
}


void LoadImageDialog::on_openBtn_clicked()
{
    ctkFileDialog dlg(this,tr("load file"),tr("select a file"));
    dlg.setModal(true);
    if(dlg.exec())
    {
        if(dlg.selectedFiles().count()!= 0)
        {
            // just load the first file
            LogMgr::instance()->LogAppDebug("Loading file:" + dlg.selectedFiles().at(0));
            m_viewer.DisplayImage(dlg.selectedFiles().at(0));
        }
    }
}
