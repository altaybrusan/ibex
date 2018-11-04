#include "butterworthlowpassfilter.h"
#include "butterworthlowpassfilterwidget.h"

#include <QVariant>
#include <vtkImageData.h>
#include <vtkObjectFactory.h>
#include <vtkStreamingDemandDrivenPipeline.h>
#include <vtkInformationVector.h>
#include <vtkInformation.h>
#include <vtkDataObject.h>
#include <vtkSmartPointer.h>
#include <vtkImageCast.h>
#include <vtkPNGWriter.h>
#include <vtkImageShiftScale.h>
#include <vtkImageLaplacian.h>
#include <vtkImageMathematics.h>
#include <vtkImageMapToWindowLevelColors.h>
#include <vtkImageActor.h>
#include <vtkTIFFWriter.h>
#include <vtkImageGaussianSmooth.h>
#include <vtkPointData.h>
#include <vtkDataArray.h>
#include <vtkImageMandelbrotSource.h>
#include <vtkImageSobel2D.h>
#include <vtkImageSliceMapper.h>
#include <vtkImageCast.h>
#include <vtkImageRFFT.h>
#include <vtkImageFFT.h>
#include <vtkImageIdealHighPass.h>
#include <vtkImageExtractComponents.h>

#define MIN_BOUND 0.001
#define MAX_BOUND 100.0
#define DEF_VALUE 0.01
#define STEP_SIZE 0.001
ButterworthLowPassFilter::ButterworthLowPassFilter()
{

    m_filterWidget =new ButterworthLowPassFilterWidget(nullptr);
    m_filterWidget->SetBoundaries(MIN_BOUND,MAX_BOUND);
    m_filterWidget->SetX(DEF_VALUE);
    m_filterWidget->SetY(DEF_VALUE);
    m_filterWidget->SetStep(STEP_SIZE);
    m_isEnabled = true;
    m_UID = 1;
    m_name="Butterworth low pass filter";
    connect(m_filterWidget,&ButterworthLowPassFilterWidget::NotifyApplyFiltering,this,&ButterworthLowPassFilter::OnApplyBtnPressed);
}

void ButterworthLowPassFilter::UpdateParameter(QString key, QVariant value)
{
    if(m_parameters.contains(key))
        m_parameters.insert(key,value);
}

QVariant ButterworthLowPassFilter::GetParameterValue(QString key)
{
    if(m_parameters.contains(key))
        return m_parameters[key];
    else
        return QVariant();
}

void ButterworthLowPassFilter::UpdateParentWidget(QWidget *parent)
{
    m_filterWidget->setParent(parent);
}

QWidget *ButterworthLowPassFilter::GetWidget()
{
    return dynamic_cast<QWidget*>(m_filterWidget);
}

void ButterworthLowPassFilter::SetInputData(QList<vtkSmartPointer<vtkImageData> > imageDataSet)
{
    m_imageDataSet = imageDataSet;
}

QList<vtkSmartPointer<vtkImageData> > ButterworthLowPassFilter::GetOutputData()
{
    return m_output;
}

void ButterworthLowPassFilter::StartAlgorithm()
{
    if(m_imageDataSet.at(0))
    {
        m_filterWidget->SetEnableBtn(false);
       CalculateFFT(m_imageDataSet.at(0));

    }
   return;
}

void ButterworthLowPassFilter::StopAlgorithm()
{


}

bool ButterworthLowPassFilter::IsEnabled()
{
   return  m_isEnabled;
}

void ButterworthLowPassFilter::SetAlgorithmEnabled(bool enabled)
{
    m_isEnabled = enabled;
    //m_filterWidget->SetWidgetEnabled(false);
}

int ButterworthLowPassFilter::GetAlgorithmUID()
{
    return m_UID;
}

int ButterworthLowPassFilter::GetNextAlgorithmUID()
{
    return -1;
}

int ButterworthLowPassFilter::GetPreviousAlgorithmUID()
{
    return -1;
}

QString ButterworthLowPassFilter::AlgorithmName()
{
    return m_name;

}

void ButterworthLowPassFilter::OnParameterUpdated()
{

}

void ButterworthLowPassFilter::OnApplyBtnPressed()
{
    emit NotifyAlgorithmStarted(m_UID);
}


void ButterworthLowPassFilter::CalculateFFT(vtkSmartPointer<vtkImageData> inputData)
{

    vtkSmartPointer<vtkImageCast> originalCastFilter =
      vtkSmartPointer<vtkImageCast>::New();
    originalCastFilter->SetInputData(inputData);
    originalCastFilter->SetOutputScalarTypeToFloat();
    originalCastFilter->Update();

    vtkSmartPointer<vtkImageGaussianSmooth> gaussianSmoothFilter =
        vtkSmartPointer<vtkImageGaussianSmooth>::New();
      gaussianSmoothFilter->SetInputConnection(originalCastFilter->GetOutputPort());
      gaussianSmoothFilter->SetRadiusFactor(2);
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
      shiftScaleFilter->SetOutputScalarTypeToFloat();
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


//     m_output.append( outputCastFilter->GetOutput());
     vtkSmartPointer<vtkTIFFWriter> writer =
       vtkSmartPointer<vtkTIFFWriter>::New();
     writer->SetFileName("demox2.png");

     writer->SetInputData(outputCastFilter->GetOutput());
     writer->Write();

     m_filterWidget->SetEnableBtn(true);
     emit NotifyAlgorithmFinished(m_UID);
}