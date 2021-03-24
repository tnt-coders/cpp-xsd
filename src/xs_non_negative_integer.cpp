#include "xs_non_negative_integer.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_non_negative_integer::xs_non_negative_integer(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_min_inclusive(0);
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_non_negative_integer::restriction_set& xs_non_negative_integer::restrictions()
{
    return m_restrictions;
}

const xs_non_negative_integer::restriction_set& xs_non_negative_integer::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
