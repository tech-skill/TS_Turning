#include <catch2/catch.hpp>
#include <QSettings>
#include "settings.h"


SCENARIO("New Settings", "[settings]")
{
    GIVEN("A new Settings_DB"){
        Settings::ClearAllSettings();
        WHEN("An object is instantiated"){
            Settings dut;
            THEN("There should be 10 materials")
                REQUIRE(dut.Stock.materials.count() == 10);     // there should be 10 different materials
            AND_THEN("Stock Settings have default values"){
                REQUIRE(dut.Stock.diameter == 20.0);
                REQUIRE(dut.Stock.material == 3.0);
                REQUIRE(dut.Stock.stickOut == 100.0);
            }
            AND_THEN("Machine Settings have default values"){
                REQUIRE(dut.Machine.maxSpindleSpeed == MAXSPINDLESPEED);
                REQUIRE(dut.Machine.maxXfeed == MAXXFEED);
                REQUIRE(dut.Machine.maxZfeed == MAXZFEED);
                REQUIRE(dut.Machine.constandSurfaceSpeed == true);
            }
        }
    }
}

SCENARIO("Change Settings", "[settings]")
{
    GIVEN("An existing Settings_DB"){
        WHEN("The Settings change"){
            Settings dut;
            dut.Machine.maxSpindleSpeed = MAXSPINDLESPEED/2;
            dut.Machine.maxXfeed = MAXXFEED/2;
            dut.Machine.maxZfeed = MAXZFEED/2;
            dut.Machine.constandSurfaceSpeed = false;
            dut.Stock.diameter = 10.0;
            dut.Stock.material = 2.0;
            dut.Stock.stickOut = 50.0;
        }
        WHEN("The Settings_DB is instantiated again"){
            Settings dut;
            THEN("The changed values are there"){
                REQUIRE(dut.Machine.maxSpindleSpeed == MAXSPINDLESPEED/2);
                REQUIRE(dut.Machine.maxXfeed == MAXXFEED/2);
                REQUIRE(dut.Machine.maxZfeed == MAXZFEED/2);
                REQUIRE(dut.Machine.constandSurfaceSpeed == false);
                REQUIRE(dut.Stock.diameter == 10.0);
                REQUIRE(dut.Stock.material == 2.0);
                REQUIRE(dut.Stock.stickOut == 50.0);
                REQUIRE(dut.Stock.materials.count() == 10);     // there should still be 10 different materials
            }
        }
    }
}
