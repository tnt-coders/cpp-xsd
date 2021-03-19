#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_unsigned_int.hpp>

using namespace tnt;

TEST_CASE("xs_unsigned_int", "[xs_unsigned_int]")
{
    xsd::xs_unsigned_int i(42);
    CHECK(i.value() == 42);
}
