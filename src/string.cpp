#include "string.hpp"

#include "any_simple_type.hpp"

#include <string>

namespace tnt::xsd
{

String::String(const std::string& value)
    : AnySimpleType(value)
{}

}  // namespace tnt::xsd
