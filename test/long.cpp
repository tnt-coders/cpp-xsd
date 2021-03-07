#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/long.hpp>

using namespace tnt;

TEST_CASE("Long", "[Long]")
{
    xsd::Long l(42);
    CHECK(l.value() == 42);
}
