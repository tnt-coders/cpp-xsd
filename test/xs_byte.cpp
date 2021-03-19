#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_byte.hpp>

using namespace tnt;

TEST_CASE("xs_byte", "[xs_byte]")
{
    xsd::xs_byte b(42);
    CHECK(b.value() == 42);
}
