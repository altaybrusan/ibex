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

    QDir pluginsDir(qApp->applicationDirPath());

    LogMgr::instance()->LogSysInfo("current directory:"+pluginsDir.currentPath());
    pluginsDir.cd("plugins");
//    QVBoxLayout *layout = new QVBoxLayout(ui->scrollAreaWidgetContents);
//    QList<QWidget*>  _deviceWidgetList;

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
         //LogMgr::instance()->LogSysInfo("processing plugin:"+fileName);

        if (plugin) {
            algorithm = qobject_cast<IAlgorithm*>(plugin);

            if (algorithm)
            {
                connect(dynamic_cast<QObject*>(algorithm),SIGNAL(NotifyAlgorithmFinished()),this,SLOT(OnAlgorithmFinished()));
                LogMgr::instance()->LogSysInfo(fileName + " is an algorithm.................");
                vtkSmartPointer<vtkImageData> input =
                   vtkSmartPointer<vtkImageData>::New();
                 // Setup the image
                 input->SetDimensions(2,2,1);
                 input->AllocateScalars(VTK_DOUBLE,1);

                 // Fill every entry of the image data with "2.0"
                 int* dims = input->GetDimensions();

                 QList<vtkSmartPointer<vtkImageData>> _imageDataSet;
                 for (int y=0; y<dims[1]; y++)
                   {
                   for (int x=0; x<dims[0]; x++)
                     {
                     input->SetScalarComponentFromDouble(x,y,0,0,2.0);
                     }
                   }

                 LogMgr::instance()->LogSysDebug("Input image: " );
                 PrintImage(input);

                 _imageDataSet.append(input);

                 algorithm->SetInputData(_imageDataSet);
                 algorithm->StartAlgorithm();



                 //vtkImageData* output = algorithm->GetOutput();

                 //LogMgr::instance()->LogSysDebug("Output image: " );
                 //PrintImage(output);


//              // There must be a mechanis to order the loaded widgets.
//                int device_type=device->GetDeviceType();
//                LogMgr::instance()->LogSysInfo("device type:"+QString::number(device_type));
//                _deviceWidgetList.append(device->GetWidget());
//                layout->addWidget(device->GetWidget());
//                QFrame *line=new QFrame(this);
//                line->setObjectName("line"+QString::number(device_type));
//                line->setGeometry(QRect(50, 160, 118, 3));
//                line->setFrameShape(QFrame::HLine);
//                line->setFrameShadow(QFrame::Sunken);
//                layout->addWidget(line);
            }
        }
    }

     //LogMgr::instance()->LogSysInfo("total number of loaded plugins:"+QString::number(_deviceWidgetList.count()));


//    LogMgr::instance()->LogSysDebug("ImageViewer is launched");
//    //when the imageviewer is called for the first time,
//    //there is no image to show. To avoid any problem,
//    //a blank image is loaded.
//    //this may not be best pracctice, but at least works fine.
//    blankImage->SetDimensions(10, 10, 1);
//    blankImage->AllocateScalars(VTK_DOUBLE,1);
//    for (int i = 0; i < 10; i++)
//        for (int j = 0; j < 10; j++)
//            blankImage->SetScalarComponentFromDouble(i, j, 0, 0, 0);

//    //force the viewer to use the blank image
//    imageViewer->SetInputData(blankImage);

//    //Defualt options for legend scale
//    legendScaleActor->TopAxisVisibilityOff();
//    legendScaleActor->RightAxisVisibilityOff();
//    legendScaleActor->SetLegendVisibility(0);

//    //renderer options are set
//    renderer->AddActor(legendScaleActor);
//    renderer->SetBackground(0,0,0);
//    renderer->ResetCameraClippingRange();

//    imageViewer->SetupInteractor(renderWindowInteractor);
//    imageViewer->SetRenderWindow(ui->qvtkWidget->GetRenderWindow());
//    imageViewer->SetRenderer(renderer);
//    imageViewer->Render();

//    renderWindowInteractor->SetInteractorStyle(style);
//    renderWindowInteractor->Initialize();


//    // thumbnailbar configuration
//    QVBoxLayout* layout =new QVBoxLayout;
//    layout->setSpacing(0);
//    layout->setMargin(1);
//    QSize _size(64,64);
//    thumbnailBar= new ctkThumbnailListWidget(this);
//    thumbnailBar->setThumbnailSize(_size);
//    thumbnailBar->setStyleSheet("background-color:black;");
//    layout->addWidget(thumbnailBar);
//    ui->thumbnailFrame->setLayout(layout);
//    connect(thumbnailBar,
//            SIGNAL(doubleClicked(ctkThumbnailLabel)),
//            this,
//            SLOT(OnThumbnailChanged(ctkThumbnailLabel)));
//    connect(ui->actionvFlip,
//            SIGNAL(toggled(bool)),
//            this,
//            SLOT(OnVerticalFlipToggled(bool)));
//    connect(ui->actionhFlip,
//            SIGNAL(toggled(bool)),
//            this,
//            SLOT(OnHorizontalFlipToggled(bool)));


//// These linese test to make toolbar (flip) operations mutually exclusive.

////    QActionGroup* toolActionGroup= new QActionGroup(this);
////    toolActionGroup->addAction(ui->actionhFlip);
////    toolActionGroup->addAction(ui->actionvFlip);
////    toolActionGroup->setExclusive(true);

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


// not implemented yet.
void ImageViewer::on_actioninvertColor_triggered()
{

}

void ImageViewer::OnAlgorithmFinished()
{
    if(algorithm == nullptr) return;
        //LogMgr::instance()->LogSysDebug("algorithm pointer is null");


  LogMgr::instance()->LogSysInfo("Output of the filter count: "+ QString::number(algorithm->GetOutputData().count()));
  PrintImage(algorithm->GetOutputData().at(0));
}

void ImageViewer::PrintImage(vtkImageData *image)
{
    int* dims = image->GetDimensions();

    for (int y=0; y<dims[1]; y++)
      {
      for (int x=0; x<dims[0]; x++)
        {
        double v = image->GetScalarComponentAsDouble(x,y,0,0);
        LogMgr::instance()->LogSysDebug(QString::number(v)+ " ");
        }
      //std::cout << std::endl;
      }

}
