#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_name.hpp>

using namespace tnt;

TEST_CASE("xs_name", "[xs_string][xs_normalized_string][xs_token][xs_name]")
{
    xsd::xs_name s("name");
    CHECK(s.value() == "name");
}
