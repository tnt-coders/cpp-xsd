#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/hex_binary.hpp>

using namespace tnt;

TEST_CASE("HexBinary", "[HexBinary]")
{
    xsd::HexBinary value("1234abcd");
    FAIL();
}
