#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/unsigned_long.hpp>

using namespace tnt;

TEST_CASE("UnsignedLong", "[UnsignedLong]")
{
    xsd::UnsignedLong l(42);
    CHECK(l.value() == 42);
}
