#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class UnsignedByte : public AnySimpleType<unsigned char>
{
public:
    UnsignedByte(const value_type& value)
        : AnySimpleType(value)
    {
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
