#include "xs_long.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_long::xs_long(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_long::restriction_set& xs_long::restrictions()
{
    return m_restrictions;
}

const xs_long::restriction_set& xs_long::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
