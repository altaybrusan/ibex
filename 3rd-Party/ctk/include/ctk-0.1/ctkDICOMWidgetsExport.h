

// .NAME __ctkDICOMWidgetsExport - manage Windows system differences
// .SECTION Description
// The __ctkDICOMWidgetsExport captures some system differences between Unix
// and Windows operating systems. 

#ifndef __ctkDICOMWidgetsExport_h
#define __ctkDICOMWidgetsExport_h

#include "ctkCompilerDetections_p.h"

#include <QtGlobal>

#if defined(Q_OS_WIN) || defined(Q_OS_SYMBIAN)
#  if defined(CTKDICOMWidgets_EXPORTS)
#    define CTK_DICOM_WIDGETS_EXPORT Q_DECL_EXPORT
#  else
#    define CTK_DICOM_WIDGETS_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(CTK_DICOM_WIDGETS_EXPORT)
//#  if defined(CTK_SHARED)
#    define CTK_DICOM_WIDGETS_EXPORT Q_DECL_EXPORT
//#  else
//#    define CTK_DICOM_WIDGETS_EXPORT
//#  endif
#endif

#endif

