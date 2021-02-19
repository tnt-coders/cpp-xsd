#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class Decimal : public AnySimpleType<long double>
{
public:
    Decimal(const long double value);

protected:
    Restrictions& restrictions();

private:
    Restrictions m_restrictions;
};

}  // namespace tnt::xsd
