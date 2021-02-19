#pragma once

#include "string.hpp"

#include <string>

namespace tnt::xsd
{

class NormalizedString : public String
{
public:
    NormalizedString(const std::string& value);

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
