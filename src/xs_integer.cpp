#include "xs_integer.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_integer::xs_integer(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_integer::restriction_set& xs_integer::restrictions()
{
    return m_restrictions;
}

const xs_integer::restriction_set& xs_integer::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
