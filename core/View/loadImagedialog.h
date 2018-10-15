#ifndef LOADIMAGEDIALOG_H
#define LOADIMAGEDIALOG_H

#include <QDialog>
#include <vtkImageViewer2.h>
#include <vtkLegendScaleActor.h>
#include <vtkDistanceWidget.h>
#include <vtkImageReader2.h>
#include <vtkImageReader2Factory.h>
#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkRenderer.h>
#include <vtkInteractorStyleImage.h>
#include <vtkImageCast.h>
#include <ctkVTKMagnifyView.h>
namespace Ui {
    class LoadImageDialog;
}


class LoadImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadImageDialog(QWidget *parent = 0);
    ~LoadImageDialog();

private slots:
    void on_loadBtn_clicked();

private:
    void LoadImage(QString filePath);
    Ui::LoadImageDialog *ui;

    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor ;
    vtkSmartPointer<vtkImageViewer2> imageViewer ;
    vtkSmartPointer<vtkLegendScaleActor> legendScaleActor ;
    vtkSmartPointer<vtkDistanceWidget> distanceWidget ;
    vtkSmartPointer<vtkImageReader2> imageReader ;
    vtkSmartPointer<vtkImageReader2Factory> imageFactory ;
    vtkSmartPointer<vtkRenderer> renderer ;
    vtkSmartPointer<vtkInteractorStyleImage> style ;
    vtkSmartPointer<vtkImageCast> castFilter;

};

#endif // LOADIMAGEDIALOG_H
