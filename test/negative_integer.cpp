#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/negative_integer.hpp>

using namespace tnt;

TEST_CASE("NegativeInteger", "[NegativeInteger]")
{
    xsd::NegativeInteger i(-1);
    CHECK(i.value() == -1);
}
