#pragma once

#include "token.hpp"

#include <string>

namespace tnt::xsd
{

class Name : public Token
{
public:
    Name(const value_type& value)
        : Token(value)
    {
        this->pattern(R"pattern(\i\c*)pattern");
        this->validate();
    }
};

}  // namespace tnt::xsd
