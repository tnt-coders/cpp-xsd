#include "xs_entities.hpp"

#include "xs_ncname.hpp"

#include <string>

namespace tnt::xsd
{

xs_entities::xs_entities(const value_type& value)
    : xs_ncname(value)
{
    this->restrict_min_length(1);
    this->validate();
}

xs_entities::restriction_set& xs_entities::restrictions()
{
    return m_restrictions;
}

const xs_entities::restriction_set& xs_entities::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
