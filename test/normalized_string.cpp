#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/normalized_string.hpp>

using namespace tnt;

TEST_CASE("NormalizedString", "[String][NormalizedString]")
{
    xsd::NormalizedString s("\t\r\ntest\t\r\ntest\t\r\n");
    CHECK(static_cast<std::string>(s) == "   test   test   ");
}
