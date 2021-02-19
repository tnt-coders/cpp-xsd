#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class Decimal : public AnySimpleType<long double>
{
public:
    Decimal(const long double value)
        : AnySimpleType(value)
    {
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
