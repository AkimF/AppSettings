#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include "appsettings_global.h"
#include <QObject>
#include <QSettings>

class APPSETTINGSSHARED_EXPORT AppSettings : public QObject
{
    Q_OBJECT

public:
    AppSettings() {}
    static QString appName;
    static QSettings *appSettings   ();
    static QVariant settingsValue   (QSettings  &settings,
                                     QString    key,
                                     QVariant   defaultValue);
    static QVariant settingsValue   (QString key,
                                     QVariant defaultValue);
    static void     setSettingsId   (const QString &value);

    private:
        static QString settingsId;
};

#endif // APPSETTINGS_H
