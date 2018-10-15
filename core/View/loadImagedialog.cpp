#include "loadImagedialog.h"
#include "ui_loadimagedialog.h"
#include "Utils/logmgr.h"
#include <vtkCamera.h>
#include <QTimer>
#include <ctkFileDialog.h>
#include <QMessageBox>

LoadImageDialog::LoadImageDialog(QWidget *parent) :
    QDialog(parent),    
    ui(new Ui::LoadImageDialog)
{
    ui->setupUi(this);
    castFilter =  vtkSmartPointer<vtkImageCast>::New();
    renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imageViewer =vtkSmartPointer<vtkImageViewer2>::New();
    legendScaleActor = vtkSmartPointer<vtkLegendScaleActor>::New();
    distanceWidget = vtkSmartPointer<vtkDistanceWidget>::New();
    imageReader = vtkSmartPointer<vtkImageReader2>::New();
    imageFactory = vtkSmartPointer<vtkImageReader2Factory>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();
    style = vtkSmartPointer<vtkInteractorStyleImage>::New();
}

LoadImageDialog::~LoadImageDialog()
{
    delete ui;
}


void LoadImageDialog::LoadImage(QString filePath)
{
    LogMgr::instance()->LogSysInfo("New Image is received:"+ filePath);

    QString fileName = filePath;
    //imageFactory decide which reader should be used this line is mandatory.
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

    castFilter =
            vtkSmartPointer<vtkImageCast>::New();
    castFilter->SetInputConnection(imageReader->GetOutputPort());
    castFilter->Update();
    imageViewer->SetInputConnection(imageReader->GetOutputPort());

    // this is not the best practice.
    // we need to estimate the initial values
    // from the image.
    imageViewer->SetColorLevel(8846);
    imageViewer->SetColorWindow(14059);

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
}

void LoadImageDialog::on_loadBtn_clicked()
{
    ctkFileDialog dlg(this,tr("load file"),tr("select a file"));
    dlg.setModal(true);
    if(dlg.exec())
    {
        if(dlg.selectedFiles().count()!= 0)
        {
            // just load the first file
            LogMgr::instance()->LogAppDebug("Loading file:" + dlg.selectedFiles().at(0));
            LoadImage(dlg.selectedFiles().at(0));
        }
    }
}
