#include "xs_nmtoken.hpp"

#include "xs_token.hpp"

#include <string>

namespace tnt::xsd
{

xs_nmtoken::xs_nmtoken(const value_type& value)
    : xs_token(value)
{
    this->restrict_pattern(R"pattern(\c+)pattern");
    this->validate();
}

xs_nmtoken::restriction_set& xs_nmtoken::restrictions()
{
    return m_restrictions;
}

const xs_nmtoken::restriction_set& xs_nmtoken::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
