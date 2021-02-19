#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/decimal.hpp>

using namespace tnt;

TEST_CASE("Decimal", "[Decimal]")
{
    xsd::Decimal d(42.42);
    CHECK(math::near(d.value(), 42.42));
}
