#pragma once

#include "token.hpp"

#include <string>

namespace tnt::xsd
{

class Name : public Token
{
public:
    Name(const value_type& value)
        : Token(value)
    {
        this->pattern(R"pattern(\i\c*)pattern");
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
