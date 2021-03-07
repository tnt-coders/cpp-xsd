#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/non_negative_integer.hpp>

using namespace tnt;

TEST_CASE("NonNegativeInteger", "[NonNegativeInteger]")
{
    xsd::NonNegativeInteger i(0);
    CHECK(i.value() == 0);
}
