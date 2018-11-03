#ifndef IALGORITHM_H
#define IALGORITHM_H
#include <QObject>
#include <QWidget>
#include "vtkImageData.h"
#include "vtkSmartPointer.h"

class IAlgorithm: public QObject
{
    Q_OBJECT

public:
    explicit IAlgorithm(QObject *parent =nullptr):QObject(parent){}
    virtual void UpdateParameter(QString key, QVariant value) = 0;
    virtual QVariant GetParameterValue(QString key) = 0;
    virtual void UpdateParentWidget(QWidget* parent)= 0;
    virtual QWidget* GetWidget() = 0;
    virtual void SetInputData(QList<vtkSmartPointer<vtkImageData>> imageDataSet) = 0;
    virtual vtkImageData GetAlgorithmOutput() = 0;
    virtual QList<vtkSmartPointer<vtkImageData>> GetOutputData() =0;
    virtual void StartAlgorithm() = 0;
    virtual void StopAlgorithm() = 0;
    virtual bool IsEnabled() = 0;
    virtual void SetAlgorithmEnabled(bool enabled) =0;
    virtual int GetAlgorithmUID() = 0;
    virtual int GetNextAlgorithmUID() = 0;
    virtual int GetPreviousAlgorithmUID() = 0;
    virtual QString AlgorithmName() = 0;

public slots:
    virtual void OnParameterUpdated()= 0;

signals:
   void NotifyAlgorithmStarted(int algorithmUID);
   void NotifyProgress(int algorithmUID, int percent);
   void NotifyError(int algorithmUID, QString message);
   void NotifyAlgorithmFinished(int algorithmUID);

   private:
    void operator=(const IAlgorithm&) =delete ;  // Not implemented.
};


Q_DECLARE_INTERFACE(IAlgorithm, "tr.edu.boun.IAlgorithm")


#endif // IALGORITHM_H
