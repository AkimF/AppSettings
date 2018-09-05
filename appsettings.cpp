#include "appsettings.h"


QString AppSettings::settingsId = "newProgram";


void AppSettings::setSettingsId(const QString &value)
{
    settingsId = value;
}

