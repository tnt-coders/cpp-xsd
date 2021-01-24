#pragma once

#include "string.hpp"

#include <string>

namespace tnt::xsd
{

class NormalizedString : public String
{
public:
    NormalizedString(const std::string& value);
};

}  // namespace tnt::xsd
