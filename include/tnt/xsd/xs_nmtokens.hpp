#pragma once

#include "xs_nmtoken.hpp"

#include <string>

namespace tnt::xsd
{

class xs_nmtokens : public xs_nmtoken
{
public:
    xs_nmtokens(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
