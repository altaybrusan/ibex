#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include "ctkQImageView.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointer.h"
#include "vtkLegendScaleActor.h"
#include "vtkImageViewer2.h"
#include "vtkDistanceWidget.h"
#include "vtkImageReader2.h"
#include "vtkImageReader2Factory.h"
#include "ctkThumbnailListWidget.h"
#include "ctkThumbnailLabel.h"
#include "vtkImageFlip.h"
#include "vtkImageCast.h"

#include "ialgorithm.h"

namespace Ui {
class ImageViewer;
}

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = 0);
    void DisplayImage(QString fileName);
    ~ImageViewer();


protected slots:
    void OnThumbnailChanged(const ctkThumbnailLabel & 	widget);
    void OnVerticalFlipToggled(bool value);
    void OnHorizontalFlipToggled(bool value);
    void on_actioninvertColor_triggered();
    void OnAlgorithmFinished();


private:

    Ui::ImageViewer *ui;
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;
    vtkSmartPointer<vtkImageViewer2> imageViewer;
    vtkSmartPointer<vtkLegendScaleActor> legendScaleActor;
    vtkSmartPointer<vtkDistanceWidget> distanceWidget;
    vtkSmartPointer<vtkImageReader2> imageReader;
    vtkSmartPointer<vtkImageReader2Factory> imageFactory;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkInteractorStyleImage> style;
    vtkSmartPointer<vtkImageData> blankImage;
    ctkThumbnailListWidget* thumbnailBar;
    vtkSmartPointer<vtkImageFlip> flipFilter;
    vtkSmartPointer<vtkImageCast> castFilter;

    QList<QString> imagelist,thumbnailList;

    bool IsValidFile(QString fullFileName);
    void UpdateThumbnailList();
    void LoadAlgorithmPlugins();

    IAlgorithm* algorithm;

};

#endif // IMAGEVIEWER_H
