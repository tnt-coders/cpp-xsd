#pragma once

#include "xs_any_simple_type.hpp"

namespace tnt::xsd
{

// Deliberately not using std::byte because it does not allow implicit conversions
class xs_byte : public xs_any_simple_type<char>
{
public:
    xs_byte(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
