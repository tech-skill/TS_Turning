#include <catch2/catch.hpp>
#include <QSettings>
#include "settings.h"

TEST_CASE("default Machine Settings", "[settings]")
{
    Settings dut;
    REQUIRE(dut.Machine.maxSpindleSpeed == MAXSPINDLESPEED);
    REQUIRE(dut.Machine.maxXfeed == MAXXFEED);
    REQUIRE(dut.Machine.maxZfeed == MAXZFEED);
    REQUIRE(dut.Machine.constandSurfaceSpeed == true);
}

<<<<<<< HEAD
TEST_CASE("default Stock Settings", "[settings]")
{
    Settings dut;
    REQUIRE(dut.Stock.diameter == 20.0);
    REQUIRE(dut.Stock.material == 3.0);
    REQUIRE(dut.Stock.stickOut == 100.0);
}

TEST_CASE("Materials Settings", "[settings]")
{
    Settings dut;
    REQUIRE(dut.Stock.materials.count() == 10);     // there should be 10 different materials
}
