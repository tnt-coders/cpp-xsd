#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_unsigned_byte.hpp>

using namespace tnt;

TEST_CASE("xs_unsigned_byte", "[xs_unsigned_byte]")
{
    xsd::xs_unsigned_byte b(42);
    CHECK(b.value() == 42);
}
