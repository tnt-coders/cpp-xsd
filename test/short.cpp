#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/short.hpp>

using namespace tnt;

TEST_CASE("Short", "[Short]")
{
    xsd::Short s(42);
    CHECK(s.value() == 42);
}
