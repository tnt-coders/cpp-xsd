#pragma once

#include "normalized_string.hpp"

#include <string>

namespace tnt::xsd
{

class Token : public NormalizedString
{
public:
    Token(const std::string& value);

private:
    Restrictions m_restrictions;
};

}  // namespace tnt::xsd
