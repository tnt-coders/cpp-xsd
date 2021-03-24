#pragma once

#include "xs_name.hpp"

#include <string>

namespace tnt::xsd
{

class xs_ncname : public xs_name
{
public:
    xs_ncname(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
