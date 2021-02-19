#include "decimal.hpp"

#include "any_simple_type.hpp"

namespace tnt::xsd
{

Decimal::Decimal(const long double value)
    : AnySimpleType(value)
{
    this->white_space(WhiteSpace::collapse);
    this->validate();
}

Decimal::Restrictions& Decimal::restrictions()
{
    return m_restrictions;
}

}  // namespace tnt::xsd
