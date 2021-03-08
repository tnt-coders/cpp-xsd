#pragma once

#include "token.hpp"

#include <string>

namespace tnt::xsd
{

class Language : public Token
{
public:
    Language(const value_type& value)
        : Token(value)
    {
        this->pattern(R"pattern([a-zA-Z]{1,8}(-[a-zA-Z0-9]{1,8})*)pattern");
        this->validate();
    }
};

}  // namespace tnt::xsd
