#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_negative_integer.hpp>

using namespace tnt;

TEST_CASE("xs_negative_integer", "[xs_negative_integer]")
{
    xsd::xs_negative_integer i(-1);
    CHECK(i.value() == -1);
}
