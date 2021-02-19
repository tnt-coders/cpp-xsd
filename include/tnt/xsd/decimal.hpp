#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class Decimal : public AnySimpleType<long double>
{
public:
    Decimal(const long double value);

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
