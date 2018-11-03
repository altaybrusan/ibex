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
class AlgorithmPluginMgr;

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent, AlgorithmPluginMgr& manager);
    void DisplayImage(QString fileName);
    ~ImageViewer();


protected slots:
    void OnThumbnailChanged(const ctkThumbnailLabel & 	widget);
    void OnVerticalFlipToggled(bool value);
    void OnHorizontalFlipToggled(bool value);
    void on_actioninvertColor_triggered();

private slots:
    void OnAlgorithmStarted(int algorithmUID);
    void OnAlgorithmProgress(int algorithmUID, int percent);
    void OnAlgorithmError(int algorithmUID, QString message);
    void OnAlgorithmFinished(int algorithmUID);

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
    QString m_lastLoadedFile;
    AlgorithmPluginMgr& m_pluginMgr;
    bool IsValidFile(QString fullFileName);
    void UpdateThumbnailList();

};

#endif // IMAGEVIEWER_H
