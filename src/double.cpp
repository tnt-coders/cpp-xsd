#include "double.hpp"

#include "any_simple_type.hpp"

namespace tnt::xsd
{

Double::Double(const double value)
    : AnySimpleType(value)
{
    this->white_space(facet::WhiteSpace::collapse);
}

}  // namespace tnt::xsd
