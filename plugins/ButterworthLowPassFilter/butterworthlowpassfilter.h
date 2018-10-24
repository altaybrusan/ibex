#ifndef BUTTERWORTHLOWPASSFILTER_H
#define BUTTERWORTHLOWPASSFILTER_H

#include "ialgorithm.h"
#include "butterworthlowpassfilter_global.h"
#include <QMap>
#include <QVariant>
#include <QList>
#include <butterworthlowpassfilterwidget.h>

class BUTTERWORTHLOWPASSFILTER_EXPORT ButterworthLowPassFilter : public QObject, public IAlgorithm
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.IAlgorithm")
    Q_INTERFACES(IAlgorithm)

public:
    ButterworthLowPassFilter();
    void UpdateParameter(QString key, QVariant value) override;
    QVariant GetParameterValue(QString key) override;
    void UpdateParentWidget(QWidget* parent) override;
    QWidget *GetWidget() override;
    void SetInputData(QList<vtkSmartPointer<vtkImageData>> imageDataSet) override;
    QList<vtkSmartPointer<vtkImageData>> GetOutputData() override;
    void StartAlgorithm() override;
    void StopAlgorithm() override;

signals:
    void NotifyAlgorithmStarted() override;
    void NotifyProgress(int percent) override;
    void NotifyError(QString message) override;
    void NotifyAlgorithmFinished() override ;

public slots:
    void OnParameterUpdated() override;

private slots:
    void OnHighFrequencyPressed();



private:
    void CalculateFFT(vtkSmartPointer<vtkImageData> inputData);

    QMap<QString,QVariant> m_parameters;
    QList<vtkSmartPointer<vtkImageData>> m_imageDataSet;
    QList<vtkSmartPointer<vtkImageData>> m_output;
    ButterworthLowPassFilterWidget* m_filterWidget;

};

#endif // BUTTERWORTHLOWPASSFILTER_H
