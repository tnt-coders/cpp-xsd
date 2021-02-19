#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class Double : public AnySimpleType<double>
{
public:
    Double(double value);

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
