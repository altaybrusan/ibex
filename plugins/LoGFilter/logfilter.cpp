#include "logfilter.h"
#include "logfilterwidget.h"

#include <QVariant>
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
#include <QDir>

#define MIN_BOUND 2
#define MAX_BOUND 10
#define DEF_VALUE 0.01
#define STEP_SIZE 1
LoGFilter::LoGFilter()
{

    m_filterWidget =new LoGFilterWidget(nullptr);
    m_filterWidget->SetBoundaries(MIN_BOUND,MAX_BOUND);
    m_filterWidget->SetStep(STEP_SIZE);
    m_isEnabled = true;
    m_UID = 1;
    m_name="LoG filter";
    connect(m_filterWidget,&LoGFilterWidget::NotifyApplyFiltering,this,&LoGFilter::OnApplyBtnPressed);
}

void LoGFilter::UpdateParameter(QString key, QVariant value)
{
    if(m_parameters.contains(key))
        m_parameters.insert(key,value);
}

QVariant LoGFilter::GetParameterValue(QString key)
{
    if(m_parameters.contains(key))
        return m_parameters[key];
    else
        return QVariant();
}

void LoGFilter::UpdateParentWidget(QWidget *parent)
{
    m_filterWidget->setParent(parent);
}

QWidget *LoGFilter::GetWidget()
{
    return dynamic_cast<QWidget*>(m_filterWidget);
}

void LoGFilter::SetInputData(QList<vtkSmartPointer<vtkImageData> > imageDataSet)
{
    if(m_imageDataSet.count()!=0)
    {
        m_imageDataSet.clear();
    }

    m_imageDataSet = imageDataSet;
}

QList<vtkSmartPointer<vtkImageData> > LoGFilter::GetOutputData()
{
    return m_output;
}

void LoGFilter::StartAlgorithm()
{
    if(m_imageDataSet.at(0))
    {
        m_filterWidget->SetEnableBtn(false);
        m_output.clear(); //clear all previous filter outputs.
        Filter(m_imageDataSet.at(0));
    }
   return;
}

void LoGFilter::StopAlgorithm()
{


}

bool LoGFilter::IsEnabled()
{
   return  m_isEnabled;
}

void LoGFilter::SetAlgorithmEnabled(bool enabled)
{
    m_isEnabled = enabled;
    //m_filterWidget->SetWidgetEnabled(false);
}

int LoGFilter::GetAlgorithmUID()
{
    return m_UID;
}

int LoGFilter::GetNextAlgorithmUID()
{
    return -1;
}

int LoGFilter::GetPreviousAlgorithmUID()
{
    return -1;
}

QString LoGFilter::AlgorithmName()
{
    return m_name;

}

void LoGFilter::OnParameterUpdated()
{

}

void LoGFilter::OnApplyBtnPressed()
{
    emit NotifyAlgorithmStarted(m_UID);
}


void LoGFilter::Filter(vtkSmartPointer<vtkImageData> inputData)
{

    int _kernelSize= m_filterWidget->GetGaussianKernelLength();
    vtkSmartPointer<vtkImageCast> originalCastFilter =
      vtkSmartPointer<vtkImageCast>::New();
    originalCastFilter->SetInputData(inputData);
    originalCastFilter->SetOutputScalarTypeToFloat();
    originalCastFilter->Update();

    vtkSmartPointer<vtkImageGaussianSmooth> gaussianSmoothFilter =
        vtkSmartPointer<vtkImageGaussianSmooth>::New();
      gaussianSmoothFilter->SetInputConnection(originalCastFilter->GetOutputPort());
      gaussianSmoothFilter->SetRadiusFactor(_kernelSize);
      gaussianSmoothFilter->Update();

    vtkSmartPointer<vtkImageLaplacian> laplacian =
      vtkSmartPointer<vtkImageLaplacian>::New();
    laplacian->SetInputConnection(gaussianSmoothFilter->GetOutputPort());
    laplacian->SetDimensionality(2);
    laplacian->Update();

    vtkSmartPointer<vtkImageMathematics> enhance =
      vtkSmartPointer<vtkImageMathematics>::New();
    enhance->SetInputConnection(0, gaussianSmoothFilter->GetOutputPort());
    enhance->SetInputConnection(1, laplacian->GetOutputPort());
    enhance->SetOperationToAdd();
    enhance->Update();

      vtkSmartPointer<vtkImageShiftScale> shiftScaleFilter =
        vtkSmartPointer<vtkImageShiftScale>::New();
      //shiftScaleFilter->SetOutputScalarTypeToFloat();
      shiftScaleFilter->SetInputConnection(enhance->GetOutputPort());
      shiftScaleFilter->SetShift(-1.0f * enhance->GetOutput()->GetScalarRange()[0]); // brings the lower bound to 0
      float oldRange = enhance->GetOutput()->GetScalarRange()[1] -
                       enhance->GetOutput()->GetScalarRange()[0];
      float newRange = 100; // We want the output [0,100] (the same as the original image)
      shiftScaleFilter->SetScale(newRange/oldRange);
      shiftScaleFilter->Update();

      // Cast the output back to unsigned char
      vtkSmartPointer<vtkImageCast> outputCastFilter =
              vtkSmartPointer<vtkImageCast>::New();
      outputCastFilter->SetInputConnection(shiftScaleFilter->GetOutputPort());
      outputCastFilter->SetOutputScalarTypeToFloat();
      outputCastFilter->Update();


      if(!QDir("filterouts").exists())
          QDir().mkdir("filterouts");
     m_output.append( outputCastFilter->GetOutput());
     vtkSmartPointer<vtkTIFFWriter> writer =
       vtkSmartPointer<vtkTIFFWriter>::New();
     writer->SetFileName("./filterouts/LoGOutput.png");
     writer->SetInputData(outputCastFilter->GetOutput());
     writer->Write();

     vtkSmartPointer<vtkTIFFWriter> writer2 =
       vtkSmartPointer<vtkTIFFWriter>::New();
     writer2->SetFileName("./filterouts/GaussianOutput.png");
     writer2->SetInputData(gaussianSmoothFilter->GetOutput());
     writer2->Write();

     vtkSmartPointer<vtkTIFFWriter> writer3 =
       vtkSmartPointer<vtkTIFFWriter>::New();

     writer3->SetFileName("./filterouts/EdgeOutput.png");
     writer3->SetInputData(laplacian->GetOutput());
     writer3->Write();

     m_filterWidget->SetEnableBtn(true);
     emit NotifyAlgorithmFinished(m_UID);
}
