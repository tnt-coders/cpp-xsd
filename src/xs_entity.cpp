#include "xs_entity.hpp"

#include "xs_ncname.hpp"

#include <string>

namespace tnt::xsd
{

xs_entity::xs_entity(const value_type& value)
    : xs_ncname(value)
{
    this->validate();
}

xs_entity::restriction_set& xs_entity::restrictions()
{
    return m_restrictions;
}

const xs_entity::restriction_set& xs_entity::restrictions() const
{
    return m_restrictions;
}

}  // namespace tnt::xsd
