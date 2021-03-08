#pragma once

#include "ncname.hpp"

#include <string>

namespace tnt::xsd
{

class IDREFS : public NCName
{
public:
    IDREFS(const value_type& value)
        : NCName(value)
    {
        this->min_length(1);
        this->validate();
    }
};

}  // namespace tnt::xsd
