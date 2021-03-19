#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_float.hpp>

using namespace tnt;

TEST_CASE("xs_float", "[xs_float]")
{
    xsd::xs_float f(42.42f);
    CHECK(math::near(f.value(), 42.42));
}
