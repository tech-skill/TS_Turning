#include <catch2/catch.hpp>
#include <QSettings>
#include "settings.h"

TEST_CASE("default Machine Settings", "[fancy]")
{
    Settings dut;
    REQUIRE(dut.Machine.maxSpindleSpeed == MAXSPINDLESPEED);
    REQUIRE(dut.Machine.maxXfeed == MAXXFEED);
    REQUIRE(dut.Machine.maxZfeed == MAXZFEED);
    REQUIRE(dut.Machine.constandSurfaceSpeed == true);
}

TEST_CASE("default Stock Settings", "[fancy]")
{
    Settings dut;
    REQUIRE(dut.Stock.diameter == 20);
    REQUIRE(dut.Stock.material == 3);
    REQUIRE(dut.Stock.stickOut == 100);
}

TEST_CASE("Materials Settings", "[fancy]")
{
    Settings dut;
    REQUIRE(dut.Stock.materials.count() == 10);     // there should be 10 different materials

}
