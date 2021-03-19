#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_entity.hpp>

using namespace tnt;

TEST_CASE("xs_entity", "[xs_string][xs_normalized_string][xs_token][xs_name][xs_ncname][xs_entity]")
{
    xsd::xs_entity s("name");
    CHECK(s.value() == "name");
}
