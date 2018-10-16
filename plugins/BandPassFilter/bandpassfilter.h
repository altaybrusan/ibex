#ifndef BANDPASFILTER_H
#define BANDPASFILTER_H

#include "ialgorithm.h"

#include "bandpassfilter_global.h"

class BANDPASSFILTERSHARED_EXPORT BandPassFilter :public QObject, public IAlgorithm
{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID "tr.edu.boun.IAlgorithm")
    Q_INTERFACES(IAlgorithm)

public:
    BandPassFilter();
    int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *) override;

};

#endif // BANDPASFILTER_H
