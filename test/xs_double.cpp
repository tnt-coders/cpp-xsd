#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_double.hpp>

using namespace tnt;

TEST_CASE("xs_double", "[xs_double]")
{
    xsd::xs_double d(42.42);
    CHECK(math::near(d.value(), 42.42));
}
