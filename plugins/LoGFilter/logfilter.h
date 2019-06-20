#ifndef BUTTERWORTHLOWPASSFILTER_H
#define BUTTERWORTHLOWPASSFILTER_H

#include "ialgorithm.h"
#include "logfilterwidget_global.h"
#include <QMap>
#include <QVariant>
#include <QList>
#include <logfilterwidget.h>

class LOGFILTER_EXPORT LoGFilter : public IAlgorithm
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.IAlgorithm")
    Q_INTERFACES(IAlgorithm)

public:
    LoGFilter();
    void UpdateParameter(QString key, QVariant value) override;
    QVariant GetParameterValue(QString key) override;
    void UpdateParentWidget(QWidget* parent) override;
    QWidget *GetWidget() override;
    void SetInputData(QList<vtkSmartPointer<vtkImageData>> imageDataSet) override;
    QList<vtkSmartPointer<vtkImageData>> GetOutputData() override;
    void StartAlgorithm() override;
    void StopAlgorithm() override;
    bool IsEnabled() override;
    void SetAlgorithmEnabled(bool enabled) override ;
    int GetAlgorithmUID() ;
    int GetNextAlgorithmUID();
    int GetPreviousAlgorithmUID();
    QString AlgorithmName() override;

public slots:
    void OnParameterUpdated() override;

private slots:
    void OnApplyBtnPressed();



private:
    void Filter(vtkSmartPointer<vtkImageData> inputData);

    QMap<QString,QVariant> m_parameters;
    QList<vtkSmartPointer<vtkImageData>> m_imageDataSet;
    QList<vtkSmartPointer<vtkImageData>> m_output;
    LoGFilterWidget* m_filterWidget;
    bool m_isEnabled;
    QString m_name;
    int m_UID;


};

#endif // BUTTERWORTHLOWPASSFILTER_H
