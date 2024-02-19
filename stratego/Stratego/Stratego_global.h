#ifndef STRATEGO_GLOBAL_H
#define STRATEGO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(STRATEGO_LIBRARY)
#  define STRATEGO_EXPORT Q_DECL_EXPORT
#else
#  define STRATEGO_EXPORT Q_DECL_IMPORT
#endif

#endif // STRATEGO_GLOBAL_H
