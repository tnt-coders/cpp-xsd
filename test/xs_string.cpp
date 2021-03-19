#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_string.hpp>

using namespace tnt;

TEST_CASE("xs_string", "[xs_string]")
{
    xsd::xs_string s("\t\r\ntest\t\r\ntest\t\r\n");
    CHECK(s.value() == "\t\r\ntest\t\r\ntest\t\r\n");
}
