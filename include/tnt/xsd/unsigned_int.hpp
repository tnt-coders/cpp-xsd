#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class UnsignedInt : public AnySimpleType<unsigned int>
{
public:
    UnsignedInt(const value_type& value)
        : AnySimpleType(value)
    {
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
