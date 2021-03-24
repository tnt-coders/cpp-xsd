#include "xs_normalized_string.hpp"

#include "xs_string.hpp"

#include <string>

namespace tnt::xsd
{

xs_normalized_string::xs_normalized_string(const value_type& value)
    : xs_string(value)
{
    this->restrict_white_space(white_space::replace);
    this->validate();
}

xs_normalized_string::restriction_set& xs_normalized_string::restrictions()
{
    return m_restrictions;
}

const xs_normalized_string::restriction_set& xs_normalized_string::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
