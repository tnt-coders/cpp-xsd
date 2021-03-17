#pragma once

#include "any_simple_type.hpp"

#include <memory>
#include <string>

namespace tnt::xsd
{

class String : public AnySimpleType<std::string>
{
public:
    String(const value_type& value)
        : AnySimpleType(value)
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
