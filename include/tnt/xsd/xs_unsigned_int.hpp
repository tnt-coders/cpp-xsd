#pragma once

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

class xs_unsigned_int : public xs_any_simple_type<unsigned int>
{
public:
    xs_unsigned_int(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
