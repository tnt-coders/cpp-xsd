#pragma once

#include "xs_string.hpp"

#include <string>

namespace tnt::xsd
{

class xs_normalized_string : public xs_string
{
public:
    xs_normalized_string(const value_type& value)
        : xs_string(value)
    {
        this->restrict_white_space(white_space::replace);
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
