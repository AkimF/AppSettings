#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QObject>
#include <QSettings>

class AppSettings : public QObject
{
    Q_OBJECT
public:
    explicit AppSettings(QObject *parent = 0) {}

    static QString appName;


    //===============================================
    static QSettings *appSettings()
    {
        static QSettings settings(QSettings::IniFormat, QSettings::UserScope, settingsId);
        return &settings;
    }


    //===============================================
    static QVariant settingsValue (QSettings  &settings,
                                   QString    key,
                                   QVariant   defaultValue)
    {
        if (!settings.contains(key)) {
            settings.setValue(key, defaultValue);
        }
        return settings.value(key, defaultValue);
    }


    //===============================================
    static QVariant settingsValue(QString key, QVariant defaultValue)
    {
        QSettings *settings = appSettings();
        if (!settings->contains(key)) {
            settings->setValue(key, defaultValue);
        }
        return settings->value(key, defaultValue);
    }


    static void setSettingsId(const QString &value);

private:
    static QString settingsId;

};

#endif // APPSETTINGS_H
