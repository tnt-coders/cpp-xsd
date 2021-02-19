#pragma once

#include "any_simple_type.hpp"

#include <memory>
#include <string>

namespace tnt::xsd
{

class String : public AnySimpleType<std::string>
{
public:
    String(const std::string& value);

protected:
    virtual Restrictions restrictions() const override
    {
        return m_restrictions;
    }

    virtual void restrictions(const Restrictions& restrictions) override
    {
        m_restrictions = restrictions;
    }

private:
    Restrictions m_restrictions;
};

}  // namespace tnt::xsd
