#include "xs_idrefs.hpp"

#include "xs_ncname.hpp"

#include <string>

namespace tnt::xsd
{

xs_idrefs::xs_idrefs(const value_type& value)
    : xs_ncname(value)
{
    this->restrict_min_length(1);
    this->validate();
}

xs_idrefs::restriction_set& xs_idrefs::restrictions()
{
    return m_restrictions;
}

const xs_idrefs::restriction_set& xs_idrefs::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
