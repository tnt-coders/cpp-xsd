#include "xs_boolean.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_boolean::xs_boolean(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_boolean::restriction_set& xs_boolean::restrictions()
{
    return m_restrictions;
}

const xs_boolean::restriction_set& xs_boolean::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
