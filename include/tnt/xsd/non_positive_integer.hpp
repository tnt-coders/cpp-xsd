#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class NonPositiveInteger : public AnySimpleType<long long>
{
public:
    NonPositiveInteger(const value_type& value)
        : AnySimpleType(value)
    {
        this->max_inclusive(0);
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
