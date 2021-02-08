#include "normalized_string.hpp"

#include "string.hpp"

#include <string>

namespace tnt::xsd
{

NormalizedString::NormalizedString(const std::string& value)
    : String(value)
{
    Restriction restriction(this);
    restriction.white_space(WhiteSpace::replace);
    restriction.apply();
}

}  // namespace tnt::xsd
