#ifndef LOGFILTER_GLOBAL_H
#define LOGFILTER_GLOBAL_H
#include <QtCore/qglobal.h>

#if defined(LOGFILTER_LIBRARY)
#  define LOGFILTER_EXPORT Q_DECL_EXPORT
#else
#  define LOGFILTER_EXPORT Q_DECL_IMPORT
#endif
#endif // LOGFILTER_GLOBAL_H
