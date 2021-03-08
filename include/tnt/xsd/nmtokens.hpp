#pragma once

#include "nmtoken.hpp"

#include <string>

namespace tnt::xsd
{

class NMTOKENS : public NMTOKEN
{
public:
    NMTOKENS(const value_type& value)
        : NMTOKEN(value)
    {
        this->min_length(1);
        this->validate();
    }
};

}  // namespace tnt::xsd
