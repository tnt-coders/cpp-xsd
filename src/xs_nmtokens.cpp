#include "xs_nmtokens.hpp"

#include "xs_nmtoken.hpp"

#include <string>

namespace tnt::xsd
{

xs_nmtokens::xs_nmtokens(const value_type& value)
    : xs_nmtoken(value)
{
    this->restrict_min_length(1);
    this->validate();
}

xs_nmtokens::restriction_set& xs_nmtokens::restrictions()
{
    return m_restrictions;
}

const xs_nmtokens::restriction_set& xs_nmtokens::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
