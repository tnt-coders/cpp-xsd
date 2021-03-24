#include "xs_token.hpp"

#include "xs_normalized_string.hpp"

#include <string>

namespace tnt::xsd
{

xs_token::xs_token(const value_type& value)
    : xs_normalized_string(value)
{
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_token::restriction_set& xs_token::restrictions()
{
    return m_restrictions;
}

const xs_token::restriction_set& xs_token::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
