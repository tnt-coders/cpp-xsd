#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/int.hpp>

using namespace tnt;

TEST_CASE("Int", "[Int]")
{
    xsd::Int i(42);
    CHECK(i.value() == 42);
}
