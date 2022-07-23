#include "settings.h"
#include <QSettings>

Settings::Settings()
{
    // initialze machine settings
    GetMachineSettings();
    // initialze stock settings
    GetStockSettings();
}

void Settings::GetMachineSettings()
{
    QSettings persistantSettings(ORGANIZATION,APPNAME);

    persistantSettings.beginGroup("Machine");
    Machine.constandSurfaceSpeed= persistantSettings.value("constandSurfaceSpeed",true).toBool();
    Machine.maxSpindleSpeed= persistantSettings.value("maxSpindleSpeed",MAXSPINDLESPEED).toDouble();
    Machine.maxZfeed= persistantSettings.value("maxZfeed",MAXZFEED).toDouble();
    Machine.maxXfeed= persistantSettings.value("maxXfeed",MAXXFEED).toDouble();
    persistantSettings.endGroup();
}

void Settings::GetStockSettings()
{
    QSettings persistantSettings(ORGANIZATION,APPNAME);

    persistantSettings.beginGroup("Stock");
    Stock.diameter= persistantSettings.value("diameter",20).toDouble();
    Stock.stickOut= persistantSettings.value("stickOut",100).toDouble();
    Stock.material= persistantSettings.value("material",3).toInt();
    persistantSettings.endGroup();
}

