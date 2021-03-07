#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/byte.hpp>

using namespace tnt;

TEST_CASE("Byte", "[Byte]")
{
    xsd::Byte b(42);
    CHECK(b.value() == 42);
}
