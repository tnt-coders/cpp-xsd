#include "token.hpp"

#include "normalized_string.hpp"

#include <string>

namespace tnt::xsd
{

Token::Token(const std::string& value)
    : NormalizedString(value)
{
    this->white_space(WhiteSpace::collapse);
    this->validate();
}

}  // namespace tnt::xsd
