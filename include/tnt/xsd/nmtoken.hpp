#pragma once

#include "token.hpp"

#include <string>

namespace tnt::xsd
{

class NMTOKEN : public Token
{
public:
    NMTOKEN(const value_type& value)
        : Token(value)
    {
        this->pattern(R"pattern(\c+)pattern");
        this->validate();
    }
};

}  // namespace tnt::xsd
