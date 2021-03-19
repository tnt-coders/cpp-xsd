#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/xsd/xs_short.hpp>

using namespace tnt;

TEST_CASE("xs_short", "[xs_short]")
{
    xsd::xs_short s(42);
    CHECK(s.value() == 42);
}
