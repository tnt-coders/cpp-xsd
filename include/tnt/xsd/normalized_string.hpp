#pragma once

#include "string.hpp"

#include <string>

namespace tnt::xsd
{

class NormalizedString : public String
{
public:
    NormalizedString(const std::string& value);

private:
    Restrictions m_restrictions;
};

}  // namespace tnt::xsd
