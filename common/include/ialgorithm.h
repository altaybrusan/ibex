#ifndef IALGORITHM_H
#define IALGORITHM_H
#include <QObject>
#include <QWidget>
#include "vtkImageData.h"
#include "vtkSmartPointer.h"

class IAlgorithm
{

public:
    virtual void UpdateParameter(QString key, QVariant value) = 0;
    virtual QVariant GetParameterValue(QString key) = 0;
    virtual void UpdateParentWidget(QWidget* parent)= 0;
    virtual QWidget* GetWidget() = 0;
    virtual void SetInputData(QList<vtkSmartPointer<vtkImageData>> imageDataSet) = 0;
    virtual QList<vtkSmartPointer<vtkImageData>> GetOutputData() =0;
    virtual void StartAlgorithm() = 0;
    virtual void StopAlgorithm() = 0;

public slots:
    virtual void OnParameterUpdated()= 0;

signals:
   virtual void NotifyAlgorithmStarted() = 0;
   virtual void NotifyProgress(int percent) = 0;
   virtual void NotifyError(QString message) = 0;
   virtual void NotifyAlgorithmFinished() = 0;

   private:
    void operator=(const IAlgorithm&) =delete ;  // Not implemented.
};


Q_DECLARE_INTERFACE(IAlgorithm, "tr.edu.boun.IAlgorithm")


#endif // IALGORITHM_H
