#pragma once

#include "xs_name.hpp"

#include <string>

namespace tnt::xsd
{

class xs_ncname : public xs_name
{
public:
    xs_ncname(const value_type& value)
        : xs_name(value)
    {
        this->restrict_pattern(R"pattern([\i-[:]][\c-[:]]*)pattern");
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
