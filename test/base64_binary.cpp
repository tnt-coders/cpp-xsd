#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/base64_binary.hpp>

using namespace tnt;

TEST_CASE("Base64Binary", "[Base64Binary]")
{
    xsd::Base64Binary value("abcd");
    FAIL();
}
