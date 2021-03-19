#pragma once

#include "xs_any_simple_type.hpp"

#include <memory>
#include <string>

namespace tnt::xsd
{

class xs_string : public xs_any_simple_type<std::string>
{
public:
    xs_string(const value_type& value)
        : xs_any_simple_type(value)
    {
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
