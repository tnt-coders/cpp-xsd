#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/id.hpp>

using namespace tnt;

TEST_CASE("ID", "[String][NormalizedString][Token][Name][NCName][ID]")
{
    xsd::ID s("Name");
    CHECK(s.value() == "Name");
}
