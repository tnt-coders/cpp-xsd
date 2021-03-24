#include "xs_hex_binary.hpp"

#include "xs_any_simple_type.hpp"

#include <string>

namespace tnt::xsd
{

xs_hex_binary::xs_hex_binary(const value_type& value)
    : xs_any_simple_type(value)
{
    this->restrict_pattern(R"pattern([0-9a-fA-F]*)pattern");
    this->restrict_white_space(white_space::collapse);
    this->validate();
}

xs_hex_binary::restriction_set& xs_hex_binary::restrictions()
{
    return m_restrictions;
}

const xs_hex_binary::restriction_set& xs_hex_binary::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
