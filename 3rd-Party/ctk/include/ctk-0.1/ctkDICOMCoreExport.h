

// .NAME __ctkDICOMCoreExport - manage Windows system differences
// .SECTION Description
// The __ctkDICOMCoreExport captures some system differences between Unix
// and Windows operating systems. 

#ifndef __ctkDICOMCoreExport_h
#define __ctkDICOMCoreExport_h

#include "ctkCompilerDetections_p.h"

#include <QtGlobal>

#if defined(Q_OS_WIN) || defined(Q_OS_SYMBIAN)
#  if defined(CTKDICOMCore_EXPORTS)
#    define CTK_DICOM_CORE_EXPORT Q_DECL_EXPORT
#  else
#    define CTK_DICOM_CORE_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(CTK_DICOM_CORE_EXPORT)
//#  if defined(CTK_SHARED)
#    define CTK_DICOM_CORE_EXPORT Q_DECL_EXPORT
//#  else
//#    define CTK_DICOM_CORE_EXPORT
//#  endif
#endif

#endif

