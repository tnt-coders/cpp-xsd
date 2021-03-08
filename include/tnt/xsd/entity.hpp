#pragma once

#include "ncname.hpp"

#include <string>

namespace tnt::xsd
{

class ENTITY : public NCName
{
public:
    ENTITY(const value_type& value)
        : NCName(value)
    {
        this->validate();
    }
};

}  // namespace tnt::xsd
