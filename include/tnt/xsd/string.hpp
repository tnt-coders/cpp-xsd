#pragma once

#include "any_simple_type.hpp"

#include <memory>
#include <string>

namespace tnt::xsd
{

class String : public AnySimpleType<std::string>
{
public:
    String(const std::string& value);

private:
    Restrictions m_restrictions;
};

}  // namespace tnt::xsd
