#include "any_simple_type.hpp"

#include <boost/algorithm/string/trim.hpp>
#include <cmath>
#include <optional>
#include <regex>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>

namespace tnt::xsd
{

template <typename T>
AnySimpleType<T>::operator value_type() const
{
    return m_value;
}

template <typename T>
AnySimpleType<T>::Restriction::Restriction(
    AnySimpleType<typename AnySimpleType<T>::value_type>* this_)
    : m_this(this_)
{}

template <typename T>
void AnySimpleType<T>::Restriction::apply()
{
    this->apply_enumeration();
    this->apply_fraction_digits();
    this->apply_length();
    this->apply_max_exclusive();
    this->apply_max_inclusive();
    this->apply_max_length();
    this->apply_min_exclusive();
    this->apply_min_inclusive();
    this->apply_min_length();
    this->apply_pattern();
    this->apply_total_digits();
    this->apply_white_space();
}

template <typename T>
std::unordered_set<typename AnySimpleType<T>::value_type>
AnySimpleType<T>::Restriction::enumeration() const
{
    return m_enumeration;
}

template <typename T>
std::optional<size_t> AnySimpleType<T>::Restriction::fraction_digits() const
{
    return m_fraction_digits;
}

template <typename T>
std::optional<size_t> AnySimpleType<T>::Restriction::length() const
{
    return m_length;
}

template <typename T>
std::optional<typename AnySimpleType<T>::value_type>
AnySimpleType<T>::Restriction::max_exclusive() const
{
    return m_max_exclusive;
}

template <typename T>
std::optional<typename AnySimpleType<T>::value_type>
AnySimpleType<T>::Restriction::max_inclusive() const
{
    return m_max_inclusive;
}

template <typename T>
std::optional<size_t> AnySimpleType<T>::Restriction::max_length() const
{
    return m_max_length;
}

template <typename T>
std::optional<typename AnySimpleType<T>::value_type>
AnySimpleType<T>::Restriction::min_exclusive() const
{
    return m_min_exclusive;
}

template <typename T>
std::optional<typename AnySimpleType<T>::value_type>
AnySimpleType<T>::Restriction::min_inclusive() const
{
    return m_min_inclusive;
}

template <typename T>
std::optional<size_t> AnySimpleType<T>::Restriction::min_length() const
{
    return m_min_length;
}

template <typename T>
std::unordered_set<std::string> AnySimpleType<T>::Restriction::pattern() const
{
    return m_pattern;
}

template <typename T>
std::optional<size_t> AnySimpleType<T>::Restriction::total_digits() const
{
    return m_total_digits;
}

template <typename T>
std::optional<typename AnySimpleType<T>::WhiteSpace>
AnySimpleType<T>::Restriction::white_space() const
{
    return m_white_space;
}

template <typename T>
void AnySimpleType<T>::Restriction::enumeration(const value_type& value)
{
    m_enumeration.insert(value);
}

template <typename T>
void AnySimpleType<T>::Restriction::fraction_digits(const size_t value, const bool fixed)
{
    if (m_this->m_fraction_digits_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'fractionDigits'");
    }

    m_this->m_fraction_digits_fixed = fixed;

    m_fraction_digits = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::length(const size_t value, const bool fixed)
{
    if (m_this->m_length_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'length'");
    }

    m_this->m_length_fixed = fixed;

    m_length = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::max_exclusive(const value_type& value, const bool fixed)
{
    if (m_this->m_max_exclusive_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'maxExclusive'");
    }

    m_this->m_max_exclusive_fixed = fixed;

    m_max_exclusive = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::max_inclusive(const value_type& value, const bool fixed)
{
    if (m_this->m_max_inclusive_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'maxInclusive'");
    }

    m_this->m_max_inclusive_fixed = fixed;

    m_max_inclusive = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::max_length(const size_t value, const bool fixed)
{
    if (m_this->m_max_length_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'maxLength'");
    }

    m_this->m_max_length_fixed = fixed;

    m_max_length = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::min_exclusive(const value_type& value, const bool fixed)
{
    if (m_this->m_min_exclusive_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'minExclusive'");
    }

    m_this->m_min_exclusive_fixed = fixed;

    m_min_exclusive = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::min_inclusive(const value_type& value, const bool fixed)
{
    if (m_this->m_min_inclusive_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'minInclusive'");
    }

    m_this->m_min_inclusive_fixed = fixed;

    m_min_inclusive = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::min_length(const size_t value, const bool fixed)
{
    if (m_this->m_min_length_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'minLength'");
    }

    m_this->m_min_length_fixed = fixed;

    m_min_length = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::pattern(const std::string& value)
{
    m_pattern.insert(value);
}

template <typename T>
void AnySimpleType<T>::Restriction::total_digits(const size_t value, const bool fixed)
{
    if (m_this->m_total_digits_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'totalDigits'");
    }

    m_this->m_total_digits_fixed = fixed;

    m_total_digits = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::white_space(const WhiteSpace& value, const bool fixed)
{
    if (m_this->m_white_space_fixed)
    {
        throw std::runtime_error("Cannot restrict fixed 'whiteSpace'");
    }

    m_this->m_white_space_fixed = fixed;

    m_white_space = value;
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_enumeration() const
{
    if (m_enumeration.empty())
    {
        return;
    }

    if (m_enumeration.find(m_this->m_value) == m_enumeration.end())
    {
        // TODO: better error message
        throw std::runtime_error("restrict_enumeration failed");
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_fraction_digits() const
{
    if (!m_fraction_digits)
    {
        return;
    }

    // Only applies to floating point types
    if constexpr (std::is_floating_point_v<value_type>)
    {
        // TODOTODOTODO
        //
        // TODO: This rounding should occur when printing to an xml file (converting to a string)
        // TODO: This should not be checked during validation
        //
        // Also use iomanip to set proper precision for printing
        //
        // TODOTODOTODO
        // const auto scale = std::pow(10, m_fraction_digits.value());
        // m_this->m_value = std::round(m_this->m_value * scale) / scale;
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_length() const
{
    if (!m_length)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        if (m_this->m_value.length() != m_length.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_length failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_max_exclusive() const
{
    if (!m_max_exclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (m_this->m_value >= m_max_exclusive.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_max_exclusive failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_max_inclusive() const
{
    if (!m_max_inclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (m_this->m_value > m_max_inclusive.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_max_inclusive failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_max_length() const
{
    if (!m_max_length)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        if (m_this->m_value.length() > m_max_length.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_max_length failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_min_exclusive() const
{
    if (!m_min_exclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (m_this->m_value <= m_min_exclusive.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_min_exclusive failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_min_inclusive() const
{
    if (!m_min_inclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (m_this->m_value < m_min_inclusive.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_min_inclusive failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_min_length() const
{
    if (!m_min_length)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        if (m_this->m_value.length() < m_min_length.value())
        {
            // TODO: Better error message
            throw std::runtime_error("restrict_min_length failed");
        }
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_pattern() const
{
    if (m_pattern.empty())
    {
        return;
    }

    // Convert the value to a string
    std::string value_as_string = std::invoke([this] {
        if constexpr (std::is_same_v<value_type, std::string>)
        {
            return m_this->m_value;
        }
        else
        {
            return std::to_string(m_this->m_value);
        }
    });

    bool valid = false;
    for (const auto& value : m_pattern)
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
void AnySimpleType<T>::Restriction::apply_total_digits() const
{
    if (!m_total_digits)
    {
        return;
    }

    // Only applies to numeric types
    if constexpr (std::is_arithmetic_v<value_type>)
    {
        const auto max = std::pow(10, m_total_digits.value()) - 1;
        if (std::abs(m_this->m_value) > max)
        {
            throw std::runtime_error("restrict_total_digits failed - value too large");
        }

        const auto min = std::pow(10, -(m_total_digits.value() + 1));
        if (std::abs(m_this->m_value) < min)
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
        // std::floor(std::log(m_this->m_value)) - 1); m_this->m_value *= scale; m_this->m_value =
        // std::round(m_this->m_value); m_this->m_value /= scale;
    }
}

template <typename T>
void AnySimpleType<T>::Restriction::apply_white_space() const
{
    if (!m_white_space)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        constexpr auto white_space_replace = [](std::string& value) {
            std::regex rx("\\t|\\r|\\n");
            value = std::regex_replace(value, rx, " ");
        };

        constexpr auto white_space_collapse = [white_space_replace](std::string& value) {
            white_space_replace(value);

            std::regex rx("\\s+");
            value = std::regex_replace(value, rx, " ");

            boost::algorithm::trim(value);
        };

        switch (m_white_space.value())
        {
            case WhiteSpace::preserve:
            {
                // Do nothing
                break;
            }
            case WhiteSpace::replace:
            {
                white_space_replace(m_this->m_value);
                break;
            }
            case WhiteSpace::collapse:
            {
                white_space_collapse(m_this->m_value);
                break;
            }
        }
    }
}

template <typename T>
AnySimpleType<T>::AnySimpleType(const value_type& value)
    : m_value(value)
{}

// Explicit template declarations (this allows us to define the template functions in the .cpp file)
template class AnySimpleType<double>;
template class AnySimpleType<long double>;
template class AnySimpleType<std::string>;

}  // namespace tnt::xsd
