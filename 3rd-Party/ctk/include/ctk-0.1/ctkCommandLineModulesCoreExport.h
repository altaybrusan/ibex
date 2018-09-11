

// .NAME __ctkCommandLineModulesCoreExport - manage Windows system differences
// .SECTION Description
// The __ctkCommandLineModulesCoreExport captures some system differences between Unix
// and Windows operating systems. 

#ifndef __ctkCommandLineModulesCoreExport_h
#define __ctkCommandLineModulesCoreExport_h

#include "ctkCompilerDetections_p.h"

#include <QtGlobal>

#if defined(Q_OS_WIN) || defined(Q_OS_SYMBIAN)
#  if defined(CTKCommandLineModulesCore_EXPORTS)
#    define CTK_CMDLINEMODULECORE_EXPORT Q_DECL_EXPORT
#  else
#    define CTK_CMDLINEMODULECORE_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(CTK_CMDLINEMODULECORE_EXPORT)
//#  if defined(CTK_SHARED)
#    define CTK_CMDLINEMODULECORE_EXPORT Q_DECL_EXPORT
//#  else
//#    define CTK_CMDLINEMODULECORE_EXPORT
//#  endif
#endif

#endif

