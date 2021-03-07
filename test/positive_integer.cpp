#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/positive_integer.hpp>

using namespace tnt;

TEST_CASE("PositiveInteger", "[PositiveInteger]")
{
    xsd::PositiveInteger i(1);
    CHECK(i.value() == 1);
}
