#pragma once

#include "name.hpp"

#include <string>

namespace tnt::xsd
{

class NCName : public Name
{
public:
    NCName(const value_type& value)
        : Name(value)
    {
        this->pattern(R"pattern([\i-[:]][\c-[:]]*)pattern");
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
