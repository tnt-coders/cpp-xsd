#pragma once

#include "ncname.hpp"

#include <string>

namespace tnt::xsd
{

class ID : public NCName
{
public:
    ID(const value_type& value)
        : NCName(value)
    {
        this->validate();
    }
};

}  // namespace tnt::xsd
