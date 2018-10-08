#include "appsettings.h"


QString AppSettings::settingsId = "newProgram";


//===========================================
QSettings *AppSettings::appSettings()
{
    static QSettings settings(QSettings::IniFormat, QSettings::UserScope, settingsId);
    return &settings;
}




//===========================================
QVariant AppSettings::settingsValue(QSettings &settings, QString key, QVariant defaultValue)
{
    if (!settings.contains(key)) {
        settings.setValue(key, defaultValue);
    }
    return settings.value(key, defaultValue);
}




//===========================================
QVariant AppSettings::settingsValue(QString key, QVariant defaultValue)
{
    QSettings *settings = appSettings();
    if (!settings->contains(key)) {
        settings->setValue(key, defaultValue);
    }
    return settings->value(key, defaultValue);
}




//===========================================
void AppSettings::setSettingsId(const QString &value)
{
    settingsId = value;
}



//===========================================


