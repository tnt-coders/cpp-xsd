#pragma once

#include "xs_token.hpp"

#include <string>

namespace tnt::xsd
{

class xs_language : public xs_token
{
public:
    xs_language(const value_type& value);

protected:
    virtual restriction_set& restrictions() override;

    virtual const restriction_set& restrictions() const override;

private:
    restriction_set m_restrictions;
};

}  // namespace tnt::xsd
