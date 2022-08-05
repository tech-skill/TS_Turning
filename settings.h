#ifndef SETTINGS_H
#define SETTINGS_H


#define ORGANIZATION    "TechSkill"
#define APPNAME         "TS_Turning"

#define MAXXFEED        3000.0
#define MAXZFEED        4000.0
#define MAXSPINDLESPEED 3000.0


#include <QStringList>
#include <QSettings>

class Settings
{
public:
    Settings();
    ~Settings();
    static void ClearAllSettings();
    void GetMachineSettings();
    void GetStockSettings();
    void SaveMachineSettings();
    void SaveStockSettings();

    struct Stock
    {  // stock
        const QStringList materials =
        {                           // material
            "Aluminum",             // 0
            "High carbon steel",    // 1
            "Mid. carbon steel",    // 2
            "Low carbon steel",     // 3
            "Stainless steel",      // 4
            "Brass",                // 5
            "Bronze",               // 6
            "Copper",               // 7
            "Titanium",             // 8
            "Plastics"              // 9
        };
        int material=3;             // default Low carbon steel
        double stickOut=100;        // 100mm stickout
        double diameter=20;         // 20mm diameter
    } Stock;

    struct Machine
    {  //machine
        double maxZfeed;
        double maxXfeed;
        double maxSpindleSpeed;
        bool constandSurfaceSpeed;
    } Machine;

};

#endif // SETTINGS_H
