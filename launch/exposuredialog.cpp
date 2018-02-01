#include "exposuredialog.h"
#include "ui_exposuredialog.h"
#include "imageviewer.h"
#include <QDebug>

ExposureDialog::ExposureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExposureDialog)
{
    ui->setupUi(this);

    auto _viewer=new ImageViewer(this);
    ui->displayFrame->layout()->addWidget(_viewer);

    QString FullFileName= QString(TEST_IMAGES_DIR) + "circle-test.tiff";
    _viewer->DisplayImage(FullFileName);
    FullFileName= QString(TEST_IMAGES_DIR) + "hand-test.tiff";
    _viewer->DisplayImage(FullFileName);

}

ExposureDialog::~ExposureDialog()
{
    delete ui;
}
