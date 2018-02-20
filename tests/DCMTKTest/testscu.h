#ifndef TESTSCU_H
#define TESTSCU_H

#include "dcmtk/config/osconfig.h"  /* make sure OS specific configuration is included first */

#include "dcmtk/dcmnet/scu.h"     /* Covers most common dcmdata classes */

class DcmTestSCU : public DcmSCU
{

public:

  DcmTestSCU()  {}
  ~DcmTestSCU() {}

};
#endif // TESTSCU_H
