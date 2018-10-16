#ifndef IALGORITHM_H
#define IALGORITHM_H
#include <QObject>
#include "vtkImageAlgorithm.h"

class IAlgorithm :public vtkImageAlgorithm
{
public:
    //static IAlgorithm *New(){}
  vtkTypeMacro(IAlgorithm,vtkImageAlgorithm)

  IAlgorithm(){}

protected:

  virtual int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *)=0;

private:
  IAlgorithm(const IAlgorithm&);  // Not implemented.
  void operator=(const IAlgorithm&);  // Not implemented.
};


Q_DECLARE_INTERFACE(IAlgorithm, "tr.edu.boun.IAlgorithm")


#endif // IALGORITHM_H
