#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/double.hpp>

using namespace tnt;

TEST_CASE("Double", "[Double]")
{
    xsd::Double d(42.42);
    CHECK(math::near(static_cast<double>(d), 42.42));
}
