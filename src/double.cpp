#include "double.hpp"

#include "any_simple_type.hpp"

namespace tnt::xsd
{

Double::Double(const double value)
    : AnySimpleType(value)
    , m_restrictions(this)
{
    m_restrictions.white_space(WhiteSpace::collapse);
    m_restriction.apply();
}

}  // namespace tnt::xsd
