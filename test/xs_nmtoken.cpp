#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_nmtoken.hpp>

using namespace tnt;

TEST_CASE("xs_nmtoken", "[xs_string][xs_normalized_string][xs_token][xs_nmtoken]")
{
    xsd::xs_nmtoken s("name");
    CHECK(s.value() == "name");
}
