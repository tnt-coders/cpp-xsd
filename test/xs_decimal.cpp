#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_decimal.hpp>

using namespace tnt;

TEST_CASE("xs_decimal", "[xs_decimal]")
{
    xsd::xs_decimal d(42.42);
    CHECK(math::near(d.value(), 42.42));
}
