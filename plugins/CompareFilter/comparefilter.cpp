#include "comparefilter.h"
#include "comparefilterwidget.h"

#include <QVariant>
#include <QTextStream>
#include <QFile>
#include <vtkImageData.h>
#include <vtkObjectFactory.h>
#include <vtkDataObject.h>
#include <vtkSmartPointer.h>
#include <vtkImageShiftScale.h>
#include <vtkImageLaplacian.h>
#include <vtkImageMathematics.h>
#include <vtkTIFFWriter.h>
#include <vtkImageGaussianSmooth.h>
#include <vtkPointData.h>
#include <vtkDataArray.h>
#include <vtkImageCast.h>
#include <vtkImageViewer2.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkImageReader2Factory.h>
#include <vtkRenderer.h>
#include <QDir>

#include <stdio.h>
#include <conio.h>
#include "xid.h"





#define MIN_BOUND 2
#define MAX_BOUND 10
#define DEF_VALUE 0.01
#define STEP_SIZE 1
CompareFilter::CompareFilter()
{

    m_filterWidget =new CompareFilterWidget(nullptr);
    m_filterWidget->SetBoundaries(MIN_BOUND,MAX_BOUND);
    m_filterWidget->SetStep(STEP_SIZE);
    m_isEnabled = true;
    m_UID = 1;
    m_name="Compare filter";
    connect(m_filterWidget,&CompareFilterWidget::NotifyApplyFiltering,this,&CompareFilter::OnApplyBtnPressed);
}

void CompareFilter::UpdateParameter(QString key, QVariant value)
{
    if(m_parameters.contains(key))
        m_parameters.insert(key,value);
}

QVariant CompareFilter::GetParameterValue(QString key)
{
    if(m_parameters.contains(key))
        return m_parameters[key];
    else
        return QVariant();
}

void CompareFilter::UpdateParentWidget(QWidget *parent)
{
    m_filterWidget->setParent(parent);
}

QWidget *CompareFilter::GetWidget()
{
    return dynamic_cast<QWidget*>(m_filterWidget);
}

void CompareFilter::SetInputData(QList<vtkSmartPointer<vtkImageData> > imageDataSet)
{
    if(m_imageDataSet.count()!=0)
    {
        m_imageDataSet.clear();
    }

    m_imageDataSet = imageDataSet;
}

QList<vtkSmartPointer<vtkImageData> > CompareFilter::GetOutputData()
{
    return m_output;
}

void CompareFilter::StartAlgorithm()
{
    if(m_imageDataSet.at(0))
    {
        m_filterWidget->SetEnableBtn(false);
        m_output.clear(); //clear all previous filter outputs.
        Filter(m_imageDataSet.at(0));
    }
   return;
}

void CompareFilter::StopAlgorithm()
{


}

bool CompareFilter::IsEnabled()
{
   return  m_isEnabled;
}

void CompareFilter::SetAlgorithmEnabled(bool enabled)
{
    m_isEnabled = enabled;
    m_filterWidget->SetWidgetEnabled(enabled);
}

int CompareFilter::GetAlgorithmUID()
{
    return m_UID;
}

int CompareFilter::GetNextAlgorithmUID()
{
    return -1;
}

int CompareFilter::GetPreviousAlgorithmUID()
{
    return -1;
}

QString CompareFilter::AlgorithmName()
{
    return m_name;

}

void CompareFilter::OnParameterUpdated()
{

}

void CompareFilter::OnApplyBtnPressed()
{
    emit NotifyAlgorithmStarted(m_UID);
}


void CompareFilter::Filter(vtkSmartPointer<vtkImageData> inputData)
{


//    int _kernelSize= m_filterWidget->GetGaussianKernelLength();
//    vtkSmartPointer<vtkImageCast> originalCastFilter =
//      vtkSmartPointer<vtkImageCast>::New();
//    originalCastFilter->SetInputData(inputData);
//    originalCastFilter->SetOutputScalarTypeToFloat();
//    originalCastFilter->Update();

//    vtkSmartPointer<vtkImageGaussianSmooth> gaussianSmoothFilter =
//        vtkSmartPointer<vtkImageGaussianSmooth>::New();
//      gaussianSmoothFilter->SetInputConnection(originalCastFilter->GetOutputPort());
//      gaussianSmoothFilter->SetRadiusFactor(_kernelSize);
//      gaussianSmoothFilter->Update();

//    vtkSmartPointer<vtkImageLaplacian> laplacian =
//      vtkSmartPointer<vtkImageLaplacian>::New();
//    laplacian->SetInputConnection(gaussianSmoothFilter->GetOutputPort());
//    laplacian->SetDimensionality(2);
//    laplacian->Update();

//    vtkSmartPointer<vtkImageMathematics> enhance =
//      vtkSmartPointer<vtkImageMathematics>::New();
//    enhance->SetInputConnection(0, gaussianSmoothFilter->GetOutputPort());
//    enhance->SetInputConnection(1, laplacian->GetOutputPort());
//    enhance->SetOperationToAdd();
//    enhance->Update();

//      vtkSmartPointer<vtkImageShiftScale> shiftScaleFilter =
//        vtkSmartPointer<vtkImageShiftScale>::New();
//      //shiftScaleFilter->SetOutputScalarTypeToFloat();
//      shiftScaleFilter->SetInputConnection(enhance->GetOutputPort());
//      shiftScaleFilter->SetShift(-1.0f * enhance->GetOutput()->GetScalarRange()[0]); // brings the lower bound to 0
//      float oldRange = enhance->GetOutput()->GetScalarRange()[1] -
//                       enhance->GetOutput()->GetScalarRange()[0];
//      float newRange = 100; // We want the output [0,100] (the same as the original image)
//      shiftScaleFilter->SetScale(newRange/oldRange);
//      shiftScaleFilter->Update();

//      // Cast the output back to unsigned char
//      vtkSmartPointer<vtkImageCast> outputCastFilter =
//              vtkSmartPointer<vtkImageCast>::New();
//      outputCastFilter->SetInputConnection(shiftScaleFilter->GetOutputPort());
//      outputCastFilter->SetOutputScalarTypeToFloat();
//      outputCastFilter->Update();


      if(!QDir("filterouts").exists())
          QDir().mkdir("filterouts");
     m_output.append( outputCastFilter->GetOutput());
//     vtkSmartPointer<vtkTIFFWriter> writer =
//       vtkSmartPointer<vtkTIFFWriter>::New();
//     writer->SetFileName("./filterouts/LoGOutput.png");
//     writer->SetInputData(outputCastFilter->GetOutput());
//     writer->Write();

//     vtkSmartPointer<vtkTIFFWriter> writer2 =
//       vtkSmartPointer<vtkTIFFWriter>::New();
//     writer2->SetFileName("./filterouts/GaussianOutput.png");
//     writer2->SetInputData(gaussianSmoothFilter->GetOutput());
//     writer2->Write();

//     vtkSmartPointer<vtkTIFFWriter> writer3 =
//       vtkSmartPointer<vtkTIFFWriter>::New();

//     writer3->SetFileName("./filterouts/EdgeOutput.png");
//     writer3->SetInputData(laplacian->GetOutput());
//     writer3->Write();


     m_filterWidget->SetEnableBtn(true);
     emit NotifyAlgorithmFinished(m_UID);
}
