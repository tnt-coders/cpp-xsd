#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/unsigned_byte.hpp>

using namespace tnt;

TEST_CASE("UnsignedByte", "[UnsignedByte]")
{
    xsd::UnsignedByte b(42);
    CHECK(b.value() == 42);
}
