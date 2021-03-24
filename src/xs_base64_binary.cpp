#include "xs_base64_binary.hpp"

#include "xs_any_simple_type.hpp"

#include <string>

namespace tnt::xsd
{

xs_base64_binary::xs_base64_binary(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_pattern(
        R"pattern((([A-Za-z0-9+/]{4})*([A-Za-z0-9+/]{4}|[A-Za-z0-9+/]{2}[AEIMQUYcgkosw048]=|[A-Za-z0-9+/][AQgw]={2}))?)pattern");
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_base64_binary::restriction_set& xs_base64_binary::restrictions()
{
    return m_restrictions;
}

const xs_base64_binary::restriction_set& xs_base64_binary::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
