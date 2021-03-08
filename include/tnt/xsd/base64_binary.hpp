#pragma once

#include "any_simple_type.hpp"

#include <string>

namespace tnt::xsd
{

class Base64Binary : public AnySimpleType<std::string>
{
public:
    Base64Binary(const value_type& value)
        : AnySimpleType(value)
    {
        // clang-format off
        this->pattern(R"pattern("
            "("
                "([A-Za-z0-9+/]{4})*"
                "("
                    "[A-Za-z0-9+/]{4}|"
                    "[A-Za-z0-9+/]{2}[AEIMQUYcgkosw048]=|"
                    "[A-Za-z0-9+/][AQgw]={2}"
                ")"
            ")?"
            ")pattern");
        // clang-format on
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
