#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/xs_idrefs.hpp>

using namespace tnt;

TEST_CASE("xs_idrefs",
          "[xs_string][xs_normalized_string][xs_token][xs_name][xs_ncname][xs_idref][xs_idrefs]")
{
    xsd::xs_idrefs s("name");
    CHECK(s.value() == "name");
}
