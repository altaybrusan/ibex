

// .NAME __ctkVisualizationVTKWidgetsExport - manage Windows system differences
// .SECTION Description
// The __ctkVisualizationVTKWidgetsExport captures some system differences between Unix
// and Windows operating systems. 

#ifndef __ctkVisualizationVTKWidgetsExport_h
#define __ctkVisualizationVTKWidgetsExport_h

#include "ctkCompilerDetections_p.h"

#include <QtGlobal>

#if defined(Q_OS_WIN) || defined(Q_OS_SYMBIAN)
#  if defined(CTKVisualizationVTKWidgets_EXPORTS)
#    define CTK_VISUALIZATION_VTK_WIDGETS_EXPORT Q_DECL_EXPORT
#  else
#    define CTK_VISUALIZATION_VTK_WIDGETS_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(CTK_VISUALIZATION_VTK_WIDGETS_EXPORT)
//#  if defined(CTK_SHARED)
#    define CTK_VISUALIZATION_VTK_WIDGETS_EXPORT Q_DECL_EXPORT
//#  else
//#    define CTK_VISUALIZATION_VTK_WIDGETS_EXPORT
//#  endif
#endif

#endif

