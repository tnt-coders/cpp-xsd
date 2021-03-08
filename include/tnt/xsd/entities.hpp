#pragma once

#include "ncname.hpp"

#include <string>

namespace tnt::xsd
{

class ENTITIES : public NCName
{
public:
    ENTITIES(const value_type& value)
        : NCName(value)
    {
        this->min_length(1);
        this->validate();
    }
};

}  // namespace tnt::xsd
