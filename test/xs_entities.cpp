#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_entities.hpp>

using namespace tnt;

TEST_CASE("xs_entities",
          "[xs_string][xs_normalized_string][xs_token][xs_name][xs_ncname][xs_entity][xs_entities]")
{
    xsd::xs_entities s("name");
    CHECK(s.value() == "name");
}
