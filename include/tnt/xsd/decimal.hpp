#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class Decimal : public AnySimpleType<long double>
{
public:
    Decimal(const value_type& value)
        : AnySimpleType(value)
    {
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
