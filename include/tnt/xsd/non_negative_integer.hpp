#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class NonNegativeInteger : public AnySimpleType<long long>
{
public:
    NonNegativeInteger(const value_type& value)
        : AnySimpleType(value)
    {
        this->min_inclusive(0);
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
