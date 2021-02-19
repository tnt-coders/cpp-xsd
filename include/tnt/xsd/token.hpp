#pragma once

#include "normalized_string.hpp"

#include <string>

namespace tnt::xsd
{

class Token : public NormalizedString
{
public:
    Token(const std::string& value)
        : NormalizedString(value)
    {
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }
};

}  // namespace tnt::xsd
