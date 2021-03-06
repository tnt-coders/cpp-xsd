#include "xs_decimal.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_decimal::xs_decimal(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_decimal::restriction_set& xs_decimal::restrictions()
{
    return m_restrictions;
}

const xs_decimal::restriction_set& xs_decimal::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
