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

ButterworthLowPassFilter::ButterworthLowPassFilter()
{

    m_filterWidget =new BandPassFilterWidget(nullptr);
    connect(m_filterWidget,&BandPassFilterWidget::NotifyStartHighFrequencyFiltering,this,&ButterworthLowPassFilter::OnHighFrequencyPressed);
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

void ButterworthLowPassFilter::OnParameterUpdated()
{

}

void ButterworthLowPassFilter::OnHighFrequencyPressed()
{
  CalculateFFT(m_imageDataSet.at(0));
}


void ButterworthLowPassFilter::CalculateFFT(vtkSmartPointer<vtkImageData> inputData)
{

    // Compute the FFT of the image
      vtkSmartPointer<vtkImageFFT> fftFilter =
              vtkSmartPointer<vtkImageFFT>::New();
      fftFilter->SetInputData(inputData);
      fftFilter->Update();

      // High pass filter the FFT

//      vtkSmartPointer<vtkImageIdealHighPass> highPassFilter =
//              vtkSmartPointer<vtkImageIdealHighPass>::New();
//      highPassFilter->SetInputConnection(fftFilter->GetOutputPort());
//      highPassFilter->SetXCutOff(.0001);
//      highPassFilter->SetYCutOff(.0001);
//      highPassFilter->Update();

      vtkSmartPointer<vtkImageButterworthLowPass> butterworthLowPass =
                    vtkSmartPointer<vtkImageButterworthLowPass>::New();
      butterworthLowPass->SetInputConnection(fftFilter->GetOutputPort());
      butterworthLowPass->SetXCutOff(0.1);
      butterworthLowPass->SetYCutOff(0.1);
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
     emit NotifyAlgorithmFinished();
}
