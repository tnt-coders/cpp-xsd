#include "xs_string.hpp"

#include "xs_any_simple_type.hpp"

#include <memory>
#include <string>

namespace tnt::xsd
{

xs_string::xs_string(const value_type& value)
    : xs_any_simple_type(value)
{
    this->validate();
}

xs_string::restriction_set& xs_string::restrictions()
{
    return m_restrictions;
}

const xs_string::restriction_set& xs_string::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
