#include "imageviewer.h"
#include "ui_imageviewer.h"

#include <QFileInfo>
#include <QMessageBox>

// CTK includes
//#include <ctkQImageView.h>
#include "ctkVTKMagnifyView.h"
#include "ctkCommandLineParser.h"
#include "ctkVTKSliceView.h"
//#include "ctkWidgetsUtils.h"
#include "ctkThumbnailListWidget.h"
#include "ctkThumbnailLabel.h"
// VTK includes
#include <vtkImageReader2Factory.h>
#include <vtkImageReader2.h>
#include <vtkSmartPointer.h>
#include <vtkInteractorStyleImage.h>
#include <vtkLightBoxRendererManager.h>
#include <vtkImageViewer2.h>
#include <vtkRendererCollection.h>
#include <vtkDistanceWidget.h>
#include <vtkDistanceRepresentation.h>
#include "QVTKWidget.h"
#include <vtkLegendScaleActor.h>
#include <vtkImageMapper.h>
#include <vtkImageData.h>
#include <vtkCamera.h>
#include <vtkImageActor.h>
#include <vtkImageFlip.h>
#include <vtkImageCast.h>
#include <vtkAlgorithm.h>


#include "Utils/logmgr.h"

#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

#include "ialgorithm.h"
#include <QPluginLoader>
#include <QDir>

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
    LoadAlgorithmPlugins();

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
void ImageViewer::DisplayImage(QString fileName)
{
    LogMgr::instance()->LogSysInfo("New Image is received:"+ fileName);

    if(IsValidFile(fileName))
    {

        // Instanciate an image reader
        // not tested for all ttypes (may not work with all tiff, dcm or jpg)
        imageReader.TakeReference(imageFactory->CreateImageReader2(fileName.toLatin1()));
        if (!imageReader)
        {
            LogMgr::instance()->LogSysDebug("failed to instanciate image reader using: " + fileName);
            QMessageBox::warning(this,tr("error loading file"),tr("can not load the file"),QMessageBox::Ok);
            return;
        }
        else
        {
            //Read image
            imageReader->SetFileName(fileName.toLatin1());
            imageReader->Update();

        }
        // internal call of UninstallPipeline() is for example triggered by re-setting render window ...
        imageViewer->SetRenderWindow(NULL);
        imageViewer->SetRenderWindow(ui->qvtkWidget->GetRenderWindow());

        castFilter =
                vtkSmartPointer<vtkImageCast>::New();
        castFilter->SetInputConnection(imageReader->GetOutputPort());
        castFilter->Update();
        imageViewer->SetInputConnection(imageReader->GetOutputPort());

        double min = imageReader->GetOutput()->GetScalarRange()[0];
        double max = imageReader->GetOutput()->GetScalarRange()[1];
        LogMgr::instance()->LogSysInfo("minimum pixel value: " + QString::number(min));
        LogMgr::instance()->LogSysInfo("maximum pixel value: " + QString::number(max));
        imageViewer->SetColorLevel((max+min)/2);
        imageViewer->SetColorWindow(max-min);
        //Defualt options for legend scale
        legendScaleActor->TopAxisVisibilityOff();
        legendScaleActor->RightAxisVisibilityOff();
        legendScaleActor->SetLegendVisibility(0);

        //renderer options are set
        renderer->AddActor(legendScaleActor);
        renderer->SetBackground(0,0,0);
        renderer->ResetCamera();


        int extent[6];
        castFilter->GetOutput()->GetExtent(extent);
        double origin[3];
        castFilter->GetOutput()->GetOrigin(origin);
        double spacing[3];
        castFilter->GetOutput()->GetSpacing(spacing);
        vtkCamera* camera = renderer->GetActiveCamera();
        camera->ParallelProjectionOn();


        float xc = origin[0] + 0.5*(extent[0] + extent[1])*spacing[0];
        float yc = origin[1] + 0.5*(extent[2] + extent[3])*spacing[1];
        //float xd = (extent[1] - extent[0] + 1)*spacing[0]; // not used
        float yd = (extent[3] - extent[2] + 1)*spacing[1];
        float d = camera->GetDistance();
        camera->SetParallelScale(0.5f*static_cast<float>(yd));
        camera->SetFocalPoint(xc,yc,0.0);
        camera->SetPosition(xc,yc,+d);
        imageViewer->SetupInteractor(renderWindowInteractor);
        imageViewer->SetRenderWindow(ui->qvtkWidget->GetRenderWindow());
        imageViewer->SetRenderer(renderer);
        imageViewer->Render();

        renderWindowInteractor->SetInteractorStyle(style);
        renderWindowInteractor->Initialize();
        imagelist.append(fileName);
        UpdateThumbnailList();
        imageViewer->UpdateDisplayExtent();

        // Read image
        //imageReader->SetFileName(fullFileName.toLatin1());
        //imageViewer->SetInputConnection(imageReader->GetOutputPort());
        //renderer->ResetCamera();
        //imageViewer->Render();
        //imagelist.append(fullFileName);
        //UpdateThumbnailList();
        //imageViewer->UpdateDisplayExtent();
        //imageReader->Update();


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

void ImageViewer::LoadAlgorithmPlugins()
{
    QDir pluginsDir(qApp->applicationDirPath());
    LogMgr::instance()->LogSysInfo("current directory:"+pluginsDir.currentPath());
    pluginsDir.cd("plugins");
    QVBoxLayout *layout = new QVBoxLayout(ui->FilterArea);
    layout->setMargin(0);
    foreach (QString fileName, pluginsDir.entryList(QDir::Files))
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
          algorithm = dynamic_cast<IAlgorithm*>(plugin);
          if(algorithm)
          {
              connect(dynamic_cast<QObject*>(algorithm),SIGNAL(NotifyAlgorithmFinished()),this,SLOT(OnAlgorithmFinished()));
              LogMgr::instance()->LogSysInfo(" iBEX is loading filter: "+ fileName);
              if(algorithm->GetWidget())
              {
                 layout->addWidget(algorithm->GetWidget());
                 QFrame *line=new QFrame(this);
                 line->setGeometry(QRect(50, 160, 118, 3));
                 line->setFrameShape(QFrame::HLine);
                 line->setFrameShadow(QFrame::Sunken);
                 layout->addWidget(line);

                 QDir testDir(qApp->applicationDirPath());
                 testDir.cd("test");

                  QString fileName = "C:\\Users\\Altay\\Documents\\Qt\\Projects\\ibex\\build\\release\\test\\phantom.tiff";

                  vtkSmartPointer<vtkImageReader2> imageReader =vtkSmartPointer<vtkImageReader2>::New();
                  vtkSmartPointer<vtkImageReader2Factory> imageFactory = vtkSmartPointer<vtkImageReader2Factory>::New();
                  imageReader.TakeReference(imageFactory->CreateImageReader2(fileName.toLatin1()));
                  if (!imageReader)
                  {
                      LogMgr::instance()->LogSysDebug("failed to instanciate image reader using: " + fileName);
                      QMessageBox::warning(this,tr("error loading file"),tr("can not load the file"),QMessageBox::Ok);
                      return;
                  }
                  else
                  {
                      //Read image
                      imageReader->SetFileName(fileName.toLatin1());
                      imageReader->Update();
                      vtkSmartPointer<vtkImageData> _imgData =
                              vtkSmartPointer<vtkImageData>::New();

                      _imgData= imageReader->GetOutput();
                      QList<vtkSmartPointer<vtkImageData>> _list;

                      _list.append(_imgData);
                      algorithm->SetInputData(_list);
                      algorithm->UpdateParentWidget(ui->FilterArea);


                  }


              }
          }
        }
}


}


// not implemented yet.
void ImageViewer::on_actioninvertColor_triggered()
{

}

void ImageViewer::OnAlgorithmFinished()
{

    LogMgr::instance()->LogSysDebug("filter operation is done");
}


