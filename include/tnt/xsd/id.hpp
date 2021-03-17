#pragma once

#include "ncname.hpp"

#include <string>

namespace tnt::xsd
{

class ID : public NCName
{
public:
    ID(const value_type& value)
        : NCName(value)
    {
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
