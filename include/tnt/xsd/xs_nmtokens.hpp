#pragma once

#include "xs_nmtoken.hpp"

#include <string>

namespace tnt::xsd
{

class xs_nmtokens : public xs_nmtoken
{
public:
    xs_nmtokens(const value_type& value)
        : xs_nmtoken(value)
    {
        this->restrict_min_length(1);
        this->validate();
    }

protected:
    virtual restriction_set& restrictions() override
    {
        return m_restrictions;
    }

    virtual const restriction_set& restrictions() const override
    {
        return m_restrictions;
    }

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
