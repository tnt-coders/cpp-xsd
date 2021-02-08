#include "double.hpp"

#include "any_simple_type.hpp"

namespace tnt::xsd
{

Double::Double(const double value)
    : AnySimpleType(value)
{
    Restriction restriction(this);
    restriction.white_space(WhiteSpace::collapse);
    restriction.apply();
}

}  // namespace tnt::xsd
