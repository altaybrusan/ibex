

// .NAME __ctkCommandLineModulesFrontendQtGuiExport - manage Windows system differences
// .SECTION Description
// The __ctkCommandLineModulesFrontendQtGuiExport captures some system differences between Unix
// and Windows operating systems. 

#ifndef __ctkCommandLineModulesFrontendQtGuiExport_h
#define __ctkCommandLineModulesFrontendQtGuiExport_h

#include "ctkCompilerDetections_p.h"

#include <QtGlobal>

#if defined(Q_OS_WIN) || defined(Q_OS_SYMBIAN)
#  if defined(CTKCommandLineModulesFrontendQtGui_EXPORTS)
#    define CTK_CMDLINEMODULEQTGUI_EXPORT Q_DECL_EXPORT
#  else
#    define CTK_CMDLINEMODULEQTGUI_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(CTK_CMDLINEMODULEQTGUI_EXPORT)
//#  if defined(CTK_SHARED)
#    define CTK_CMDLINEMODULEQTGUI_EXPORT Q_DECL_EXPORT
//#  else
//#    define CTK_CMDLINEMODULEQTGUI_EXPORT
//#  endif
#endif

#endif

