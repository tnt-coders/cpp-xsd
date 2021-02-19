#pragma once

#include "any_simple_type.hpp"

namespace tnt::xsd
{

template <typename SimpleType>
class Double : public AnySimpleType<Double<SimpleType>, double>
{
public:
    Double(double value);

private:
    Restrictions m_restrictions;
};

}  // namespace tnt::xsd
