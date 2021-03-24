#include "xs_idref.hpp"

#include "xs_ncname.hpp"

#include <string>

namespace tnt::xsd
{

xs_idref::xs_idref(const value_type& value)
    : xs_ncname(value)
{
    this->validate();
}

xs_idref::restriction_set& xs_idref::restrictions()
{
    return m_restrictions;
}

const xs_idref::restriction_set& xs_idref::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
