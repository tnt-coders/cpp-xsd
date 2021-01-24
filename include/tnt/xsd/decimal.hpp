#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class Decimal : public AnySimpleType<long double>
{
public:
    Decimal(const long double value);
};

}  // namespace tnt::xsd
