#pragma once

#include "string.hpp"

#include <string>

namespace tnt::xsd
{

class NormalizedString : public String
{
public:
    NormalizedString(const value_type& value)
        : String(value)
    {
        this->white_space(WhiteSpace::replace);
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
