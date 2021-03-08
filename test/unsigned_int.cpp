#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/unsigned_int.hpp>

using namespace tnt;

TEST_CASE("UnsignedInt", "[UnsignedInt]")
{
    xsd::UnsignedInt i(42);
    CHECK(i.value() == 42);
}
