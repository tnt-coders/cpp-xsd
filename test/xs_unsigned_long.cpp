#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_unsigned_long.hpp>

using namespace tnt;

TEST_CASE("xs_unsigned_long", "[xs_unsigned_long]")
{
    xsd::xs_unsigned_long l(42);
    CHECK(l.value() == 42);
}
