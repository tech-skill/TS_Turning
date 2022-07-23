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
