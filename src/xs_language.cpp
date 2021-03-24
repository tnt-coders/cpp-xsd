#include "xs_language.hpp"

#include "xs_token.hpp"

#include <string>

namespace tnt::xsd
{

xs_language::xs_language(const value_type& value)
    : xs_token(value)
{
    this->restrict_pattern(R"pattern([a-zA-Z]{1,8}(-[a-zA-Z0-9]{1,8})*)pattern");
    this->validate();
}

xs_language::restriction_set& xs_language::restrictions()
{
    return m_restrictions;
}

const xs_language::restriction_set& xs_language::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
