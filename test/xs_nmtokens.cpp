#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_nmtokens.hpp>

using namespace tnt;

TEST_CASE("xs_nmtokens", "[xs_string][xs_normalized_string][xs_token][xs_nmtoken][xs_nmtokens]")
{
    xsd::xs_nmtokens s("name");
    CHECK(s.value() == "name");
}
