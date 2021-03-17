#pragma once

#include "ncname.hpp"

#include <string>

namespace tnt::xsd
{

class ENTITIES : public NCName
{
public:
    ENTITIES(const value_type& value)
        : NCName(value)
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
