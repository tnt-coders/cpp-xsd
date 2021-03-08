#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class PositiveInteger : public AnySimpleType<unsigned long long>
{
public:
    PositiveInteger(const value_type& value)
        : AnySimpleType(value)
    {
        this->min_exclusive(0);
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
