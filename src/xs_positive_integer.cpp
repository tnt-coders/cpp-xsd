#include "xs_positive_integer.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_positive_integer::xs_positive_integer(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_min_exclusive(0);
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_positive_integer::restriction_set& xs_positive_integer::restrictions()
{
    return m_restrictions;
}

const xs_positive_integer::restriction_set& xs_positive_integer::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
