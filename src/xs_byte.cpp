#include "xs_byte.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_byte::xs_byte(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_byte::restriction_set& xs_byte::restrictions()
{
    return m_restrictions;
}

const xs_byte::restriction_set& xs_byte::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
