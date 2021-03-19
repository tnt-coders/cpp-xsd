#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_positive_integer.hpp>

using namespace tnt;

TEST_CASE("xs_positive_integer", "[xs_positive_integer]")
{
    xsd::xs_positive_integer i(1);
    CHECK(i.value() == 1);
}
