#include "xs_int.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_int::xs_int(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_int::restriction_set& xs_int::restrictions()
{
    return m_restrictions;
}

const xs_int::restriction_set& xs_int::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
