#include <catch2/catch_test_macros.hpp>
#include <tnt/xsd/language.hpp>

using namespace tnt;

TEST_CASE("Language", "[String][NormalizedString][Token][Language]")
{
    xsd::Language s("EN-US");
    CHECK(s.value() == "EN-US");
}
