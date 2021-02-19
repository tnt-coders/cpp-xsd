#include "any_simple_type.hpp"

#include <boost/algorithm/string/trim.hpp>
#include <cmath>
#include <optional>
#include <regex>
#include <stdexcept>
#include <string>
#include <unordered_set>

namespace tnt::xsd
{

template <typename T>
AnySimpleType<T>::operator value_type() const
{
    return m_value;
}

template <typename T>
void AnySimpleType<T>::enumeration(const value_type& value)
{
    this->restrictions().enumeration.insert(value);
}

template <typename T>
void AnySimpleType<T>::fraction_digits(const size_t value, const bool fixed)
{
    if (m_fraction_digits_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'fractionDigits'");
    }

    m_fraction_digits_fixed = fixed;

    this->restrictions().fraction_digits = value;
}

template <typename T>
void AnySimpleType<T>::length(const size_t value, const bool fixed)
{
    if (m_length_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'length'");
    }

    m_length_fixed = fixed;

    this->restrictions().length = value;
}

template <typename T>
void AnySimpleType<T>::max_exclusive(const value_type& value, const bool fixed)
{
    if (m_max_exclusive_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'maxExclusive'");
    }

    m_max_exclusive_fixed = fixed;

    this->restrictions().max_exclusive = value;
}

template <typename T>
void AnySimpleType<T>::max_inclusive(const value_type& value, const bool fixed)
{
    if (m_max_inclusive_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'maxInclusive'");
    }

    m_max_inclusive_fixed = fixed;

    this->restrictions().max_inclusive = value;
}

template <typename T>
void AnySimpleType<T>::max_length(const size_t value, const bool fixed)
{
    if (m_max_length_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'maxLength'");
    }

    m_max_length_fixed = fixed;

    this->restrictions().max_length = value;
}

template <typename T>
void AnySimpleType<T>::min_exclusive(const value_type& value, const bool fixed)
{
    if (m_min_exclusive_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'minExclusive'");
    }

    m_min_exclusive_fixed = fixed;

    this->restrictions().min_exclusive = value;
}

template <typename T>
void AnySimpleType<T>::min_inclusive(const value_type& value, const bool fixed)
{
    if (m_min_inclusive_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'minInclusive'");
    }

    m_min_inclusive_fixed = fixed;

    this->restrictions().min_inclusive = value;
}

template <typename T>
void AnySimpleType<T>::min_length(const size_t value, const bool fixed)
{
    if (m_min_length_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'minLength'");
    }

    m_min_length_fixed = fixed;

    this->restrictions().min_length = value;
}

template <typename T>
void AnySimpleType<T>::pattern(const std::string& value)
{
    this->restrictions().pattern.insert(value);
}

template <typename T>
void AnySimpleType<T>::total_digits(const size_t value, const bool fixed)
{
    if (m_total_digits_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'totalDigits'");
    }

    m_total_digits_fixed = fixed;

    m_total_digits = value;
}

template <typename T>
void AnySimpleType<T>::white_space(const WhiteSpace& value, const bool fixed)
{
    if (m_white_space_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'whiteSpace'");
    }

    m_white_space_fixed = fixed;

    this->restrictions().white_space = value;
}

template <typename T>
void AnySimpleType<T>::validate() const
{
    this->validate_enumeration();
    this->validate_fraction_digits();
    this->validate_length();
    this->validate_max_exclusive();
    this->validate_max_inclusive();
    this->validate_max_length();
    this->validate_min_exclusive();
    this->validate_min_inclusive();
    this->validate_
}

template <typename T>
void AnySimpleType<T>::validate_enumeration() const
{
    const auto restrictions = this->restrictions();
    if (restrictions.enumeration.empty())
    {
        return;
    }

    if (restrictions.enumeration.find(m_value) == restrictions.enumeration.end())
    {
        // TODO: better error message
        throw std::runtime_error("validate_enumeration failed");
    }
}

template <typename T>
void AnySimpleType<T>::validate_fraction_digits() const
{
    const auto restrictions = this->restrictions();
    if (!restrictions.fraction_digits)
    {
        return;
    }

    // Only applies to floating point types
    if constexpr (std::is_floating_point_v<value_type>)
    {
        const auto order_of_magnitude = std::floor(std::log(std::abs(m_value)));

        if (order_of_magnitude < 0 && std::abs(order_of_magnitude) > restrictions.fraction_digits.value())
        {
            throw std::runtime_error("restrict_fraction_digits failed - value too small");
        }

        // TODOTODOTODO
        //
        // TODO: This rounding should occur when printing to an xml file (converting to a string)
        // TODO: This should not be checked during validation
        //
        // Also use iomanip to set proper precision for printing
        //
        // TODOTODOTODO
        // const auto scale = std::pow(10, m_fraction_digits.value());
        // m_simple_type->m_value = std::round(m_simple_type->m_value * scale) / scale;
    }
}

template <typename T>
void AnySimpleType<T>::validate_length() const
{
    const auto restrictions = this->restrictions();
    if (!restrictions.length)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        if (m_value.length() != restrictions.length.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_length failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::validate_max_exclusive() const
{
    const auto restrictions = this->restrictions();
    if (!restrictions.max_exclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (m_value >= restrictions.max_exclusive.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_max_exclusive failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::validate_max_inclusive() const
{
    const auto restrictions = this->restrictions();
    if (!restrictions.max_inclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (m_value > restrictions.max_inclusive.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_max_inclusive failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::validate_max_length() const
{
    const auto restrictions = this->restrictions();
    if (!restrictions.max_length)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        if (m_value.length() > restrictions.max_length.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_max_length failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::validate_min_exclusive() const
{
    const auto restrictions = this->restrictions();
    if (!restrictions.min_exclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (m_value <= restrictions.min_exclusive.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_min_exclusive failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::validate_min_inclusive() const
{
    const auto restrictions = this->restrictions();
    if (!restrictions.min_inclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (m_value < restrictions.min_inclusive.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_min_inclusive failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::validate_min_length() const
{
    const auto restrictions = this->restrictions();
    if (!restrictions.min_length)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        if (m_value.length() < restrictions.min_length.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_min_length failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::validate_pattern() const
{
    const auto restrictions = this->restrictions();
    if (restrictions.pattern.empty())
    {
        return;
    }

    // Convert the value to a string
    // TODO: Give each type its own overload of "<<" that converts it to a string
    //       Numeric types should round properly
    //       Boolean should match pattern restriction
    std::string value_as_string = std::invoke([this] {
        if constexpr (std::is_same_v<value_type, std::string>)
        {
            return m_value;
        }
        else
        {
            return std::to_string(m_value);
        }
    });

    bool valid = false;
    for (const auto& value : restrictions.pattern)
    {
        const std::regex rx(value);
        if (std::regex_match(value_as_string, rx))
        {
            valid = true;
        }
    }

    if (!valid)
    {
        // TODO: Better error message
        throw std::runtime_error("restrict_pattern failed");
    }
}

template <typename T>
void AnySimpleType<T>::validate_total_digits() const
{
    const auto restrictions = this->restrictions();
    if (!restrictions.total_digits)
    {
        return;
    }

    // Only applies to numeric types
    if constexpr (std::is_arithmetic_v<value_type>)
    {
        const auto order_of_magnitude = std::floor(std::log(std::abs(m_value)));

        if (order_of_magnitude >= restrictions.total_digits.value())
        {
            throw std::runtime_error("restrict_total_digits failed - value too large");
        }

        else if (order_of_magnitude < 0
                 && std::abs(order_of_magnitude) > restrictions.total_digits.value())
        {
            throw std::runtime_error("restrict_total_digits failed - value too small");
        }

        // TODOTODOTODO
        //
        // TODO: This rounding should occur when printing to an xml file (converting to a string)
        // TODO: This should not be checked during validation
        //
        // Also use iomanip to set proper precision for printing
        //
        // TODOTODOTODO
        // const auto scale = std::pow(10, m_total_digits.value() -
        // std::floor(std::log(m_simple_type->m_value)) - 1);
        // m_simple_type->m_value = std::round(m_simple_type->m_value * scale) / scale;
    }
}

template <typename T>
void AnySimpleType<T>::validate_white_space() const
{
    // Nothing to do here
}

//template <typename T>
//void AnySimpleType<T>::Restrictions::apply_white_space() const
//{
//    if (!m_white_space)
//    {
//        return;
//    }
//
//    // Only applies to string types
//    if constexpr (std::is_same_v<value_type, std::string>)
//    {
//        constexpr auto white_space_replace = [](std::string& value) {
//            std::regex rx("\\t|\\r|\\n");
//            value = std::regex_replace(value, rx, " ");
//        };
//
//        constexpr auto white_space_collapse = [white_space_replace](std::string& value) {
//            white_space_replace(value);
//
//            std::regex rx("\\s+");
//            value = std::regex_replace(value, rx, " ");
//
//            boost::algorithm::trim(value);
//        };
//
//        switch (m_white_space.value())
//        {
//            case WhiteSpace::preserve:
//            {
//                // Do nothing
//                break;
//            }
//            case WhiteSpace::replace:
//            {
//                white_space_replace(m_simple_type->m_value);
//                break;
//            }
//            case WhiteSpace::collapse:
//            {
//                white_space_collapse(m_simple_type->m_value);
//                break;
//            }
//        }
//    }
//}

template <typename T>
AnySimpleType<T>::AnySimpleType(const value_type& value)
    : m_value(value)
{}

// Explicit template declarations (this allows us to define the template functions in the .cpp file)
template class AnySimpleType<double>;
template class AnySimpleType<long double>;
template class AnySimpleType<std::string>;

}  // namespace tnt::xsd
