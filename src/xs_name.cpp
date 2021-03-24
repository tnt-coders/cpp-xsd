#include "xs_name.hpp"

#include "xs_token.hpp"

#include <string>

namespace tnt::xsd
{

xs_name::xs_name(const value_type& value)
    : xs_token(value)
{
    this->restrict_pattern(R"pattern(\i\c*)pattern");
    this->validate();
}

xs_name::restriction_set& xs_name::restrictions()
{
    return m_restrictions;
}

const xs_name::restriction_set& xs_name::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
