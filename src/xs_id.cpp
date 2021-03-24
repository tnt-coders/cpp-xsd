#include "xs_id.hpp"

#include "xs_ncname.hpp"

#include <string>

namespace tnt::xsd
{

xs_id::xs_id(const value_type& value)
    : xs_ncname(value)
{
    this->validate();
}

xs_id::restriction_set& xs_id::restrictions()
{
    return m_restrictions;
}

const xs_id::restriction_set& xs_id::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
