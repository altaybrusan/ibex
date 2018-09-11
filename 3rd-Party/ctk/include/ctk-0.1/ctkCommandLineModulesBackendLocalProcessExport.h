

// .NAME __ctkCommandLineModulesBackendLocalProcessExport - manage Windows system differences
// .SECTION Description
// The __ctkCommandLineModulesBackendLocalProcessExport captures some system differences between Unix
// and Windows operating systems. 

#ifndef __ctkCommandLineModulesBackendLocalProcessExport_h
#define __ctkCommandLineModulesBackendLocalProcessExport_h

#include "ctkCompilerDetections_p.h"

#include <QtGlobal>

#if defined(Q_OS_WIN) || defined(Q_OS_SYMBIAN)
#  if defined(CTKCommandLineModulesBackendLocalProcess_EXPORTS)
#    define CTK_CMDLINEMODULEBACKENDLP_EXPORT Q_DECL_EXPORT
#  else
#    define CTK_CMDLINEMODULEBACKENDLP_EXPORT Q_DECL_IMPORT
#  endif
#endif

#if !defined(CTK_CMDLINEMODULEBACKENDLP_EXPORT)
//#  if defined(CTK_SHARED)
#    define CTK_CMDLINEMODULEBACKENDLP_EXPORT Q_DECL_EXPORT
//#  else
//#    define CTK_CMDLINEMODULEBACKENDLP_EXPORT
//#  endif
#endif

#endif

