#include "normalized_string.hpp"

#include "string.hpp"

#include <string>

namespace tnt::xsd
{

NormalizedString::NormalizedString(const std::string& value)
    : String(value)
{
    this->white_space(facet::WhiteSpace::replace);
    this->validate();
}

}  // namespace tnt::xsd
