#pragma once

#include "xs_token.hpp"

#include <string>

namespace tnt::xsd
{

class xs_nmtoken : public xs_token
{
public:
    xs_nmtoken(const value_type& value)
        : xs_token(value)
    {
        this->restrict_pattern(R"pattern(\c+)pattern");
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