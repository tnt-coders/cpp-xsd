#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/token.hpp>

using namespace tnt;

TEST_CASE("Token", "[String][NormalizedString][Token]")
{
    xsd::Token s("\t\r\ntest\t\r\ntest\t\r\n");
    CHECK(static_cast<std::string>(s) == "test test");
}
