#pragma once

#include "normalized_string.hpp"

#include <string>

namespace tnt::xsd
{

class Token : public NormalizedString
{
public:
    Token(const value_type& value)
        : NormalizedString(value)
    {
        this->white_space(WhiteSpace::collapse);
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
