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

}  // namespace tnt::xsd
