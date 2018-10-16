#include "bandpassfilter.h"
#include <QVariant>

#include "vtkImageData.h"
#include "vtkObjectFactory.h"
#include "vtkStreamingDemandDrivenPipeline.h"
#include "vtkInformationVector.h"
#include "vtkInformation.h"
#include "vtkDataObject.h"
#include "vtkSmartPointer.h"


void BandPassFilter::UpdateParameter(QString key, QVariant value)
{
    if(m_parameters.contains(key))
        m_parameters.insert(key,value);
}

QVariant BandPassFilter::GetParameterValue(QString key)
{
    if(m_parameters.contains(key))
        return m_parameters[key];
    else
        return QVariant();
}

void BandPassFilter::UpdateParentWidget(QWidget *parent)
{
    m_parentWidget = parent;
}

QWidget *BandPassFilter::GetWidget()
{
    return new QWidget();
}

void BandPassFilter::SetInputData(QList<vtkSmartPointer<vtkImageData> > imageDataSet)
{
    m_imageDataSet = imageDataSet;
}

QList<vtkSmartPointer<vtkImageData> > BandPassFilter::GetOutputData()
{
    return m_output;
}

void BandPassFilter::StartAlgorithm()
{
      // Get the input and ouptut
      vtkSmartPointer<vtkImageData> input = m_imageDataSet.at(0);
      vtkSmartPointer<vtkImageData> image =
      vtkSmartPointer<vtkImageData>::New();

      image->ShallowCopy(input);
      image->SetScalarComponentFromDouble(0,0,0,0, 5.0);

      m_output.append(image);

      emit NotifyAlgorithmFinished();
   return;
}

void BandPassFilter::StopAlgorithm()
{

}

void BandPassFilter::OnParameterUpdated()
{

}
