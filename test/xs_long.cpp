#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_long.hpp>

using namespace tnt;

TEST_CASE("xs_long", "[xs_long]")
{
    xsd::xs_long l(42);
    CHECK(l.value() == 42);
}
