#pragma once

#include "token.hpp"

#include <string>

namespace tnt::xsd
{

class NMTOKEN : public Token
{
public:
    NMTOKEN(const value_type& value)
        : Token(value)
    {
        this->pattern(R"pattern(\c+)pattern");
        this->validate();
    }

protected:
    virtual Restrictions& restrictions() override
    {
        return m_restrictions;
    }

    virtual const Restrictions& restrictions() const override
    {
        return m_restrictions;
    }

private:
    Restrictions m_restrictions;
};

}  // namespace tnt::xsd
