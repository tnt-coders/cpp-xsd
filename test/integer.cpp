#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/integer.hpp>

using namespace tnt;

TEST_CASE("Integer", "[Integer]")
{
    xsd::Integer i(42);
    CHECK(i.value() == 42);
}
