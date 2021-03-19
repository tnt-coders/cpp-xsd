#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_ncname.hpp>

using namespace tnt;

TEST_CASE("xs_ncname", "[xs_string][xs_normalized_string][xs_token][xs_name][xs_ncname]")
{
    xsd::xs_name s("name");
    CHECK(s.value() == "name");
}
