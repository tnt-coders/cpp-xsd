#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

class NonPositiveInteger : public AnySimpleType<long long>
{
public:
    NonPositiveInteger(const value_type& value)
        : AnySimpleType(value)
    {
        this->max_inclusive(0);
        this->white_space(WhiteSpace::collapse);
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
