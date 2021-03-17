#pragma once

#include "nmtoken.hpp"

#include <string>

namespace tnt::xsd
{

class NMTOKENS : public NMTOKEN
{
public:
    NMTOKENS(const value_type& value)
        : NMTOKEN(value)
    {
        this->min_length(1);
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
