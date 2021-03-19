#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_base64_binary.hpp>

using namespace tnt;

TEST_CASE("xs_base64_binary", "[xs_base64_binary]")
{
    xsd::xs_base64_binary value("abcd");
    FAIL();
}
