#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/float.hpp>

using namespace tnt;

TEST_CASE("Float", "[Float]")
{
    xsd::Float f(42.42f);
    CHECK(math::near(f.value(), 42.42));
}
