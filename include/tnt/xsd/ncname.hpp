#pragma once

#include "name.hpp"

#include <string>

namespace tnt::xsd
{

class NCName : public Name
{
public:
    NCName(const value_type& value)
        : Name(value)
    {
        this->pattern(R"pattern([\i-[:]][\c-[:]]*)pattern");
        this->validate();
    }
};

}  // namespace tnt::xsd
