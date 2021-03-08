#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/unsigned_short.hpp>

using namespace tnt;

TEST_CASE("UnsignedShort", "[UnsignedShort]")
{
    xsd::UnsignedShort s(42);
    CHECK(s.value() == 42);
}
