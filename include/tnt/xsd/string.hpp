#pragma once

#include "any_simple_type.hpp"

#include <memory>
#include <string>

namespace tnt::xsd
{

class String : public AnySimpleType<std::string>
{
public:
    String(const value_type& value)
        : AnySimpleType(value)
    {
        this->validate();
    }
};

}  // namespace tnt::xsd
