#include "token.hpp"

#include "normalized_string.hpp"

#include <string>

namespace tnt::xsd
{

Token::Token(const std::string& value)
    : NormalizedString(value)
    , m_restriction(this)
{
    m_restriction.white_space(WhiteSpace::collapse);
    m_restriction.apply();
}

}  // namespace tnt::xsd
