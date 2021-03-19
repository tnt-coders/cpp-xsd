#pragma once

#include "xs_any_simple_type.hpp"

#include <string>

namespace tnt::xsd
{

class xs_base64_binary : public xs_any_simple_type<std::string>
{
public:
    xs_base64_binary(const value_type& value)
        : xs_any_simple_type(value)
    {
        this->restrict_pattern(
            R"pattern((([A-Za-z0-9+/]{4})*([A-Za-z0-9+/]{4}|[A-Za-z0-9+/]{2}[AEIMQUYcgkosw048]=|[A-Za-z0-9+/][AQgw]={2}))?)pattern");
        this->restrict_white_space(white_space::collapse);
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
