#include "xs_float.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_float::xs_float(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_float::restriction_set& xs_float::restrictions()
{
    return m_restrictions;
}

const xs_float::restriction_set& xs_float::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
