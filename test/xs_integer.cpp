#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_integer.hpp>

using namespace tnt;

TEST_CASE("xs_integer", "[xs_integer]")
{
    xsd::xs_integer i(42);
    CHECK(i.value() == 42);
}
