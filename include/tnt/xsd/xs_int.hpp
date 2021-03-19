#pragma once

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

class xs_int : public xs_any_simple_type<int>
{
public:
    xs_int(const value_type& value)
        : xs_any_simple_type(value)
    {
        this->restrict_white_space(white_space::collapse);
        this->validate();
    }

protected:
    virtual restriction_set& restrictions() override
    {
        return m_restrictions;
    }

    virtual const restriction_set& restrictions() const override
    {
        return m_restrictions;
    }

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
