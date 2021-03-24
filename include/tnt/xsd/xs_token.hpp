#pragma once

#include "xs_normalized_string.hpp"

#include <string>

namespace tnt::xsd
{

class xs_token : public xs_normalized_string
{
public:
    xs_token(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
