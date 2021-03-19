#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_idref.hpp>

using namespace tnt;

TEST_CASE("xs_idref", "[xs_string][xs_normalized_string][xs_token][xs_name][xs_ncname][xs_idref]")
{
    xsd::xs_idref s("name");
    CHECK(s.value() == "name");
}
