#include "xs_negative_integer.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_negative_integer::xs_negative_integer(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_max_exclusive(0);
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_negative_integer::restriction_set& xs_negative_integer::restrictions()
{
    return m_restrictions;
}

const xs_negative_integer::restriction_set& xs_negative_integer::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
