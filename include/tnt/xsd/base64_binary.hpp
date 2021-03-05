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
        this->pattern(
            "(?(DEFINE)"
                "(?<B64>[A-Za-z0-9+/])"
                "(?<B16>[AEIMQUYcgkosw048])"
                "(?<B04>[AQgw])"
            ")"
            "("
                "((?&B64){4})*"
                "("
                    "(?&B64){4}|"
                    "(?&B64){2}(?&B16)=|"
                    "(?&B64)(?&B04)={2}"
                ")"
            ")?");
        // clang-format on
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
