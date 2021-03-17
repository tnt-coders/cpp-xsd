#pragma once

#include "any_simple_type.hpp"

#include <string>

namespace tnt::xsd
{

class HexBinary : public AnySimpleType<std::string>
{
public:
    HexBinary(const value_type& value)
        : AnySimpleType(value)
    {
        this->pattern(R"pattern([0-9a-fA-F]*)pattern");
        this->white_space(WhiteSpace::collapse);
        this->validate();
    }

protected:
    virtual Restrictions& restrictions() override
    {
        return m_restrictions;
    }

    virtual const Restrictions& restrictions() const override
    {
        return m_restrictions;
    }

private:
    Restrictions m_restrictions;
};

}  // namespace tnt::xsd
