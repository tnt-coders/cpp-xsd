#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/nmtoken.hpp>

using namespace tnt;

TEST_CASE("NMTOKEN", "[String][NormalizedString][Token][NMTOKEN]")
{
    xsd::NMTOKEN s("Name");
    CHECK(s.value() == "Name");
}
