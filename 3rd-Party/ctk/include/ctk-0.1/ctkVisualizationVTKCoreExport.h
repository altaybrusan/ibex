

// .NAME __ctkVisualizationVTKCoreExport - manage Windows system differences
// .SECTION Description
// The __ctkVisualizationVTKCoreExport captures some system differences between Unix
// and Windows operating systems. 

#ifndef __ctkVisualizationVTKCoreExport_h
#define __ctkVisualizationVTKCoreExport_h

#include "ctkCompilerDetections_p.h"

#include <QtGlobal>

#if defined(Q_OS_WIN) || defined(Q_OS_SYMBIAN)
#  if defined(CTKVisualizationVTKCore_EXPORTS)
#    define CTK_VISUALIZATION_VTK_CORE_EXPORT Q_DECL_EXPORT
#  else
#    define CTK_VISUALIZATION_VTK_CORE_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(CTK_VISUALIZATION_VTK_CORE_EXPORT)
//#  if defined(CTK_SHARED)
#    define CTK_VISUALIZATION_VTK_CORE_EXPORT Q_DECL_EXPORT
//#  else
//#    define CTK_VISUALIZATION_VTK_CORE_EXPORT
//#  endif
#endif

#endif

