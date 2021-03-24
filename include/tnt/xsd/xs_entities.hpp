#pragma once

#include "xs_ncname.hpp"

#include <string>

namespace tnt::xsd
{

class xs_entities : public xs_ncname
{
public:
    xs_entities(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
