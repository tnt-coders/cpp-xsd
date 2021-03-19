#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_normalized_string.hpp>

using namespace tnt;

TEST_CASE("xs_normalized_string", "[xs_string][xs_normalized_string]")
{
    const xsd::xs_normalized_string s("\t\r\ntest\t\r\ntest\t\r\n");

    CHECK(s.value() == "   test   test   ");
}
