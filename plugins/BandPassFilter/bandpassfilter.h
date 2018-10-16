#ifndef BANDPASFILTER_H
#define BANDPASFILTER_H

#include "ialgorithm.h"
#include "bandpassfilter_global.h"
#include <QMap>
#include <QVariant>
#include <QList>

class BANDPASSFILTERSHARED_EXPORT BandPassFilter : public QObject, public IAlgorithm
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.IAlgorithm")
    Q_INTERFACES(IAlgorithm)

    void UpdateParameter(QString key, QVariant value) override;
    QVariant GetParameterValue(QString key) override;
    void UpdateParentWidget(QWidget* parent) override;
    QWidget *GetWidget() override;
    void SetInputData(QList<vtkSmartPointer<vtkImageData>> imageDataSet) override;
    QList<vtkSmartPointer<vtkImageData>> GetOutputData() override;
    void StartAlgorithm() override;
    void StopAlgorithm() override;

public slots:
    void OnParameterUpdated() override;

signals:
    void NotifyAlgorithmStarted();
    void NotifyProgress(int percent) ;
    void NotifyError(QString message) ;
    void NotifyAlgorithmFinished() ;

private:

    QMap<QString,QVariant> m_parameters;
    QList<vtkSmartPointer<vtkImageData>> m_imageDataSet;
    QList<vtkSmartPointer<vtkImageData>> m_output;
    QWidget* m_parentWidget;

};

#endif // BANDPASFILTER_H
