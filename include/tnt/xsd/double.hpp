#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class Double : public AnySimpleType<double>
{
public:
    Double(double value);
};

}  // namespace tnt::xsd
