#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_token.hpp>

using namespace tnt;

TEST_CASE("xs_token", "[xs_string][xs_normalized_string][xs_token]")
{
    xsd::xs_token s("\t\r\ntest\t\r\ntest\t\r\n");
    CHECK(s.value() == "test test");
}
