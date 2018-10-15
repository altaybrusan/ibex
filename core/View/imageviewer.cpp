#include "imageviewer.h"
#include "ui_imageviewer.h"
#include <ctkQImageView.h>
#include <QDebug>
#include <QFileInfo>

// CTK includes
#include "ctkVTKMagnifyView.h"
#include "ctkCommandLineParser.h"
#include "ctkVTKSliceView.h"
#include "ctkWidgetsUtils.h"
#include "ctkThumbnailListWidget.h"
#include "ctkThumbnailLabel.h"


// VTK includes
#include <vtkImageReader2Factory.h>
#include <vtkImageReader2.h>
#include <vtkImageData.h>
#include <vtkSmartPointer.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkLightBoxRendererManager.h>
#include <vtkImageViewer2.h>
#include <vtkSmartPointer.h>
#include <vtkTIFFReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRendererCollection.h>
#include <vtkInteractorStyleImage.h>
#include <vtkTextRendererStringToImage.h>
#include <vtkDistanceWidget.h>
#include <vtkDistanceRepresentation.h>
#include "QVTKWidget.h"
#include <vtkLegendScaleActor.h>
#include <vtkAxisActor2D.h>
#include <vtkCommand.h>
#include <vtkImageMapper.h>
#include <vtkImageData.h>
#include <vtkCamera.h>
#include <vtkImageActor.h>
#include <vtkImageFlip.h>
#include <vtkImageCast.h>
#include <vtkImageMapper3D.h>
#include <vtkAlgorithm.h>


// STD includes
//#include <iostream>
#include "Utils/logmgr.h"

#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkDistanceWidget.h>
#include <vtkDistanceRepresentation.h>


ImageViewer::ImageViewer(QWidget *parent) :
    QMainWindow(parent),
    renderWindowInteractor(vtkSmartPointer<vtkRenderWindowInteractor>::New()),
    legendScaleActor(vtkSmartPointer<vtkLegendScaleActor>::New()),
    imageViewer(vtkSmartPointer<vtkImageViewer2>::New()),
    distanceWidget(vtkSmartPointer<vtkDistanceWidget>::New()),
    imageReader(vtkSmartPointer<vtkImageReader2>::New()),
    imageFactory(vtkSmartPointer<vtkImageReader2Factory>::New()),
    renderer(vtkRenderer::New()),
    style(vtkSmartPointer<vtkInteractorStyleImage>::New()),
    blankImage(vtkImageData::New()),
    flipFilter(vtkSmartPointer<vtkImageFlip>::New()),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);

    LogMgr::instance()->LogSysDebug("ImageViewer is launched");
    //when the imageviewer is called for the first time,
    //there is no image to show. To avoid any problem,
    //a blank image is loaded.
    //this may not be best pracctice, but at least works fine.
    blankImage->SetDimensions(10, 10, 1);
    blankImage->AllocateScalars(VTK_DOUBLE,1);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            blankImage->SetScalarComponentFromDouble(i, j, 0, 0, 0);

    //force the viewer to use the blank image
    imageViewer->SetInputData(blankImage);

    //Defualt options for legend scale
    legendScaleActor->TopAxisVisibilityOff();
    legendScaleActor->RightAxisVisibilityOff();
    legendScaleActor->SetLegendVisibility(0);

    //renderer options are set
    renderer->AddActor(legendScaleActor);
    renderer->SetBackground(0,0,0);
    renderer->ResetCameraClippingRange();

    imageViewer->SetupInteractor(renderWindowInteractor);
    imageViewer->SetRenderWindow(ui->qvtkWidget->GetRenderWindow());
    imageViewer->SetRenderer(renderer);
    imageViewer->Render();

    renderWindowInteractor->SetInteractorStyle(style);
    renderWindowInteractor->Initialize();


    // thumbnailbar configuration
    QVBoxLayout* layout =new QVBoxLayout;
    layout->setSpacing(0);
    layout->setMargin(1);
    QSize _size(64,64);
    thumbnailBar= new ctkThumbnailListWidget(this);
    thumbnailBar->setThumbnailSize(_size);
    thumbnailBar->setStyleSheet("background-color:black;");
    layout->addWidget(thumbnailBar);
    ui->thumbnailFrame->setLayout(layout);
    connect(thumbnailBar,
            SIGNAL(doubleClicked(ctkThumbnailLabel)),
            this,
            SLOT(OnThumbnailChanged(ctkThumbnailLabel)));
    connect(ui->actionvFlip,
            SIGNAL(toggled(bool)),
            this,
            SLOT(OnVerticalFlipToggled(bool)));
    connect(ui->actionhFlip,
            SIGNAL(toggled(bool)),
            this,
            SLOT(OnHorizontalFlipToggled(bool)));


// These linese test to make toolbar (flip) operations mutually exclusive.

//    QActionGroup* toolActionGroup= new QActionGroup(this);
//    toolActionGroup->addAction(ui->actionhFlip);
//    toolActionGroup->addAction(ui->actionvFlip);
//    toolActionGroup->setExclusive(true);

}

ImageViewer::~ImageViewer()
{
    delete ui;
}

void ImageViewer::OnThumbnailChanged(const ctkThumbnailLabel &widget)
{
    DisplayImage(widget.text());
}


// this image flip is not the best practice. find a better solutipn for the next iteration
void ImageViewer::OnVerticalFlipToggled(bool value)
{
    imageViewer->GetInput();
    flipFilter->SetInputConnection(imageReader->GetOutputPort());
    if(value)
    {
        flipFilter->SetFilteredAxis(0);
    }
    else
    {
        flipFilter->SetFilteredAxis(-2);
    }

    imageViewer->SetInputConnection(flipFilter->GetOutputPort());
    flipFilter->Update();
    imageViewer->Render();
}

// this image flip is not the best practice. find a better solutipn for the next iteration
void ImageViewer::OnHorizontalFlipToggled(bool value)
{

    //instead of fliping image, you can flip camera.
    //imageViewer->GetRenderer()->GetActiveCamera()->Yaw(180);

    //flipXFilter->AddInputData(imageViewer->GetImageActor()->GetInput());
    flipFilter->SetInputConnection(imageReader->GetOutputPort());
    if(value)
    {
        //ui->actionvFlip->setChecked(false);
        flipFilter->SetFilteredAxis(1);
    }
    else
    {
        flipFilter->SetFilteredAxis(-1);

    }


    imageViewer->SetInputConnection(flipFilter->GetOutputPort());
    flipFilter->Update();
    imageViewer->Render();

}

/**
* Returns if a given full-file-name \a fullFileName is a valid file name or not
*/
bool ImageViewer::IsValidFile(QString fullFileName)
{
    QFileInfo check_file(fullFileName);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}

/**
* Display an image file
*/
void ImageViewer::DisplayImage(QString fullFileName)
{
    if(IsValidFile(fullFileName))
    {

        // Instanciate an image reader
        // not tested for all ttypes (may not work with all tiff, dcm or jpg)
        imageReader.TakeReference(imageFactory->CreateImageReader2(fullFileName.toLatin1()));
        if (!imageReader)
        {
            LogMgr::instance()->LogSysError("failed to to instanciate image reader: " + fullFileName);
            return;
        }
        // internal call of UninstallPipeline() is for example triggered by re-setting render window ...
        imageViewer->SetRenderWindow(NULL);
        imageViewer->SetRenderWindow(ui->qvtkWidget->GetRenderWindow());

        // This is not best practice
        // I have used it here for our TDI-detector
        // automate it for the next iteration
        imageViewer->SetColorLevel(8846);
        imageViewer->SetColorWindow(14059);

        // Read image
        imageReader->SetFileName(fullFileName.toLatin1());
        imageViewer->SetInputConnection(imageReader->GetOutputPort());
        renderer->ResetCamera();
        imageViewer->Render();
        imagelist.append(fullFileName);
        UpdateThumbnailList();
        imageViewer->UpdateDisplayExtent();
        imageReader->Update();


    }

}

void ImageViewer::UpdateThumbnailList()
{
    foreach (QString item, imagelist) {
        if(!thumbnailList.contains(item))
        {
            thumbnailList.append(item);
            QPixmap map(item);
            thumbnailBar->addThumbnail(map,item);
        }
    }
}


// not implemented yet.
void ImageViewer::on_actioninvertColor_triggered()
{

}
