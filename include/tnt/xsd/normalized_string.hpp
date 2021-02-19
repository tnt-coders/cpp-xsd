#pragma once

#include "string.hpp"

#include <string>

namespace tnt::xsd
{

class NormalizedString : public String
{
public:
    NormalizedString(const std::string& value)
        : String(value)
    {
        this->white_space(WhiteSpace::replace);
        this->validate();
    }
};

}  // namespace tnt::xsd
