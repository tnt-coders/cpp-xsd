#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class Double : public AnySimpleType<double>
{
public:
    Double(double value)
        : AnySimpleType(value)
    {
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
