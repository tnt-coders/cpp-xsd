#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/string.hpp>

using namespace tnt;

TEST_CASE("String", "[String]")
{
    xsd::String s("test");
}