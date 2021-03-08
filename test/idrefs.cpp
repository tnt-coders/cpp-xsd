#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/idrefs.hpp>

using namespace tnt;

TEST_CASE("IDREFS", "[String][NormalizedString][Token][Name][NCName][IDREF][IDREFS]")
{
    xsd::IDREFS s("Name");
    CHECK(s.value() == "Name");
}
