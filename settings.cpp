#include "settings.h"
#include <QSettings>

Settings::Settings()
{
    // initialze machine settings
    GetMachineSettings();
    // initialze stock settings
    GetStockSettings();
}

Settings::~Settings()
{
    // save machine settings on exit
    SaveMachineSettings();
    // save stock settings on exit
    SaveStockSettings();
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

void Settings::SaveMachineSettings()
{
    QSettings persistantSettings(ORGANIZATION,APPNAME);

    persistantSettings.beginGroup("Machine");
        persistantSettings.setValue("constandSurfaceSpeed",Machine.constandSurfaceSpeed);
        persistantSettings.setValue("maxSpindleSpeed",Machine.maxSpindleSpeed);
        persistantSettings.setValue("maxZfeed",Machine.maxZfeed);
        persistantSettings.setValue("maxXfeed",Machine.maxXfeed);
    persistantSettings.endGroup();
}

void Settings::SaveStockSettings()
{
    QSettings persistantSettings(ORGANIZATION,APPNAME);

    persistantSettings.beginGroup("Stock");
        persistantSettings.value("diameter",Stock.diameter);
        persistantSettings.value("stickOut",Stock.stickOut);
        persistantSettings.value("material",Stock.material);
    persistantSettings.endGroup();
}
