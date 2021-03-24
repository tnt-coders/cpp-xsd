#pragma once

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

class xs_short : public xs_any_simple_type<short>
{
public:
    xs_short(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
