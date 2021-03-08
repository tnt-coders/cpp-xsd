#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/name.hpp>

using namespace tnt;

TEST_CASE("Name", "[String][NormalizedString][Token][Name]")
{
    xsd::Name s("Name");
    CHECK(s.value() == "Name");
}
