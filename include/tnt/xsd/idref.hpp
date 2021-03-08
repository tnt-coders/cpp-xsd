#pragma once

#include "ncname.hpp"

#include <string>

namespace tnt::xsd
{

class IDREF : public NCName
{
public:
    IDREF(const value_type& value)
        : NCName(value)
    {
        this->validate();
    }
};

}  // namespace tnt::xsd
