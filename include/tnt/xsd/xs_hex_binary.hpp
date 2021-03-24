#pragma once

#include "xs_any_simple_type.hpp"

#include <string>

namespace tnt::xsd
{

class xs_hex_binary : public xs_any_simple_type<std::string>
{
public:
    xs_hex_binary(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
