#include "token.hpp"

#include "normalized_string.hpp"

#include <string>

namespace tnt::xsd
{

Token::Token(const std::string& value)
    : NormalizedString(value)
{
    Restriction restriction(this);
    restriction.white_space(WhiteSpace::collapse);
    restriction.apply();
}

}  // namespace tnt::xsd
