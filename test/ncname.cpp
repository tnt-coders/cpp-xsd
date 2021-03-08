#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/ncname.hpp>

using namespace tnt;

TEST_CASE("NCName", "[String][NormalizedString][Token][Name][NCName]")
{
    xsd::Name s("Name");
    CHECK(s.value() == "Name");
}
