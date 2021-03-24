#pragma once

#include "xs_token.hpp"

#include <string>

namespace tnt::xsd
{

class xs_nmtoken : public xs_token
{
public:
    xs_nmtoken(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
