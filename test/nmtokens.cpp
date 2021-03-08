#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/nmtokens.hpp>

using namespace tnt;

TEST_CASE("NMTOKENS", "[String][NormalizedString][Token][NMTOKEN][NMTOKENS]")
{
    xsd::NMTOKENS s("Name");
    CHECK(s.value() == "Name");
}
