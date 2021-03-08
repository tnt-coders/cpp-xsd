#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/idref.hpp>

using namespace tnt;

TEST_CASE("IDREF", "[String][NormalizedString][Token][Name][NCName][IDREF]")
{
    xsd::IDREF s("Name");
    CHECK(s.value() == "Name");
}
