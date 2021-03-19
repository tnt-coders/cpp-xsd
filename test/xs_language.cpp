#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_language.hpp>

using namespace tnt;

TEST_CASE("xs_language", "[xs_string][xs_normalized_string][xs_token][xs_language]")
{
    xsd::xs_language s("EN-US");
    CHECK(s.value() == "EN-US");
}
