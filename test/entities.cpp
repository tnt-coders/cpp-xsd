#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/entities.hpp>

using namespace tnt;

TEST_CASE("ENTITIES", "[String][NormalizedString][Token][Name][NCName][ENTITY][ENTITIES]")
{
    xsd::ENTITIES s("Name");
    CHECK(s.value() == "Name");
}
