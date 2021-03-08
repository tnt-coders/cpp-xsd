#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/entity.hpp>

using namespace tnt;

TEST_CASE("ENTITY", "[String][NormalizedString][Token][Name][NCName][ENTITY]")
{
    xsd::ENTITY s("Name");
    CHECK(s.value() == "Name");
}
