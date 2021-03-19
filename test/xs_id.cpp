#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_id.hpp>

using namespace tnt;

TEST_CASE("xs_id", "[xs_string][xs_normalized_string][xs_token][xs_name][xs_ncname][xs_id]")
{
    xsd::xs_id s("name");
    CHECK(s.value() == "name");
}
