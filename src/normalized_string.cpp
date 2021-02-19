#include "normalized_string.hpp"

#include "string.hpp"

#include <string>

namespace tnt::xsd
{

NormalizedString::NormalizedString(const std::string& value)
    : String(value)
    , m_restriction(this)
{
    m_restriction.white_space(WhiteSpace::replace);
    m_restriction.apply();
}

}  // namespace tnt::xsd
