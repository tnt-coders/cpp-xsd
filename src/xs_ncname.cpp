#include "xs_ncname.hpp"

#include "xs_name.hpp"

#include <string>

namespace tnt::xsd
{

xs_ncname::xs_ncname(const value_type& value)
    : xs_name(value)
{
    this->restrict_pattern(R"pattern([\i-[:]][\c-[:]]*)pattern");
    this->validate();
}

xs_ncname::restriction_set& xs_ncname::restrictions()
{
    return m_restrictions;
}

const xs_ncname::restriction_set& xs_ncname::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
