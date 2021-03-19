#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_hex_binary.hpp>

using namespace tnt;

TEST_CASE("xs_hex_binary", "[xs_hex_binary]")
{
    xsd::xs_hex_binary value("1234abcd");
    FAIL();
}
