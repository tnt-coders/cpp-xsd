#include "xs_unsigned_short.hpp"

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

xs_unsigned_short::xs_unsigned_short(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_unsigned_short::restriction_set& xs_unsigned_short::restrictions()
{
    return m_restrictions;
}

const xs_unsigned_short::restriction_set& xs_unsigned_short::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
