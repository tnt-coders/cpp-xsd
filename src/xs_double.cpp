#include "xs_double.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_double::xs_double(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_double::restriction_set& xs_double::restrictions()
{
    return m_restrictions;
}

const xs_double::restriction_set& xs_double::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
