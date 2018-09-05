#ifndef APPSETTINGS_GLOBAL_H
#define APPSETTINGS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(APPSETTINGS_LIBRARY)
#  define APPSETTINGSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define APPSETTINGSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // APPSETTINGS_GLOBAL_H