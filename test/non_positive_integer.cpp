#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/non_positive_integer.hpp>

using namespace tnt;

TEST_CASE("NonPositiveInteger", "[NonPositiveInteger]")
{
    xsd::NonPositiveInteger i(0);
    CHECK(i.value() == 0);
}
