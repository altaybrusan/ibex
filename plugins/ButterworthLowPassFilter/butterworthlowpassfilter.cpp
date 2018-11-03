#include "butterworthlowpassfilter.h"
#include <QVariant>


#include "vtkImageData.h"
#include "vtkObjectFactory.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkInformationVector.h"
#include "vtkInformation.h"
#include "vtkDataObject.h"
#include "vtkSmartPointer.h"
#include "butterworthlowpassfilterwidget.h"
#include <vtkImageFFT.h>
#include <vtkImageCast.h>
#include <vtkPNGWriter.h>
#include <vtkImageIdealHighPass.h>
#include <vtkImageRFFT.h>
#include <vtkImageExtractComponents.h>
#include <vtkImageShiftScale.h>
#include <vtkImageSlice.h>
#include <vtkImageSliceMapper.h>
#include <vtkImageButterworthLowPass.h>
#define MIN_BOUND 0.001
#define MAX_BOUND 0.1
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

   CalculateFFT(m_imageDataSet.at(0));
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
    CalculateFFT(m_imageDataSet.at(0));
}


void ButterworthLowPassFilter::CalculateFFT(vtkSmartPointer<vtkImageData> inputData)
{
    double _x = m_filterWidget->GetX();
    double _y = m_filterWidget->GetY();
    // Compute the FFT of the image
      vtkSmartPointer<vtkImageFFT> fftFilter =
              vtkSmartPointer<vtkImageFFT>::New();
      fftFilter->SetInputData(inputData);
      fftFilter->Update();

      // ButterworthLowPass the FFT

      vtkSmartPointer<vtkImageButterworthLowPass> butterworthLowPass =
                    vtkSmartPointer<vtkImageButterworthLowPass>::New();
      butterworthLowPass->SetInputConnection(fftFilter->GetOutputPort());
      butterworthLowPass->SetXCutOff(_x);
      butterworthLowPass->SetYCutOff(_y);
      butterworthLowPass->Update();

      // Compute the IFFT of the high pass filtered image
      vtkSmartPointer<vtkImageRFFT> rfftFilter =
              vtkSmartPointer<vtkImageRFFT>::New();
      //rfftFilter->SetInputConnection(highPassFilter->GetOutputPort());
      rfftFilter->SetInputConnection(butterworthLowPass->GetOutputPort());
      rfftFilter->Update();

      vtkSmartPointer<vtkImageExtractComponents> extractRealFilter =
        vtkSmartPointer<vtkImageExtractComponents>::New();
      extractRealFilter->SetInputConnection(rfftFilter->GetOutputPort());
      extractRealFilter->SetComponents(0);
      extractRealFilter->Update();

      vtkSmartPointer<vtkImageShiftScale> shiftScaleFilter =
        vtkSmartPointer<vtkImageShiftScale>::New();
      shiftScaleFilter->SetOutputScalarTypeToUnsignedChar();
      shiftScaleFilter->SetInputConnection(extractRealFilter->GetOutputPort());
      shiftScaleFilter->SetShift(-1.0f * extractRealFilter->GetOutput()->GetScalarRange()[0]); // brings the lower bound to 0
      float oldRange = extractRealFilter->GetOutput()->GetScalarRange()[1] -
              extractRealFilter->GetOutput()->GetScalarRange()[0];
      float newRange = 100; // We want the output [0,100] (the same as the original image)
      shiftScaleFilter->SetScale(newRange/oldRange);
      shiftScaleFilter->Update();

      // Cast the output back to unsigned char
      vtkSmartPointer<vtkImageCast> outputCastFilter =
              vtkSmartPointer<vtkImageCast>::New();
      outputCastFilter->SetInputConnection(shiftScaleFilter->GetOutputPort());
      outputCastFilter->SetOutputScalarTypeToUnsignedChar();
      outputCastFilter->Update();


     vtkSmartPointer<vtkPNGWriter> writer =
       vtkSmartPointer<vtkPNGWriter>::New();
     writer->SetFileName("demo.png");

     writer->SetInputData(outputCastFilter->GetOutput());
     writer->Write();
     m_filterWidget->SetEnableBtn(true);
     emit NotifyAlgorithmFinished(m_UID);
}
