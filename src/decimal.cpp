#include "decimal.hpp"

#include "any_simple_type.hpp"

namespace tnt::xsd
{

Decimal::Decimal(const long double value)
    : AnySimpleType(value)
{
    Restriction restriction(this);
    restriction.white_space(WhiteSpace::collapse);
    restriction.apply();
}

}  // namespace tnt::xsd
