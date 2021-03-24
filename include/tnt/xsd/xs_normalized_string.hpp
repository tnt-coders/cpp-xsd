#pragma once

#include "xs_string.hpp"

#include <string>

namespace tnt::xsd
{

class xs_normalized_string : public xs_string
{
public:
    xs_normalized_string(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
