#pragma once

#include "xs_any_simple_type.hpp"

#include "xml.hpp"

#include <boost/algorithm/string.hpp>
#include <regex>
#include <sstream>
#include <string>

namespace tnt::xsd
{
template <typename T>
typename xs_any_simple_type<T>::value_type xs_any_simple_type<T>::value() const
{
    return m_value;
}

template <typename T>
xs_any_simple_type<T>::xs_any_simple_type(const value_type& value)
    : m_value(value)
{}

template <typename T>
void xs_any_simple_type<T>::restrict_enumeration(const value_type& value)
{
    this->restrictions().enumeration.insert(value);
}

template <typename T>
void xs_any_simple_type<T>::restrict_fraction_digits(const size_t value)
{
    this->restrictions().fraction_digits = value;
}

template <typename T>
void xs_any_simple_type<T>::restrict_length(const size_t value)
{
    this->restrictions().length = value;
}

template <typename T>
void xs_any_simple_type<T>::restrict_max_exclusive(const value_type& value)
{
    this->restrictions().max_exclusive = value;
}

template <typename T>
void xs_any_simple_type<T>::restrict_max_inclusive(const value_type& value)
{
    this->restrictions().max_inclusive = value;
}

template <typename T>
void xs_any_simple_type<T>::restrict_max_length(const size_t value)
{
    this->restrictions().max_length = value;
}

template <typename T>
void xs_any_simple_type<T>::restrict_min_exclusive(const value_type& value)
{
    this->restrictions().min_exclusive = value;
}

template <typename T>
void xs_any_simple_type<T>::restrict_min_inclusive(const value_type& value)
{
    this->restrictions().min_inclusive = value;
}

template <typename T>
void xs_any_simple_type<T>::restrict_min_length(const size_t value)
{
    this->restrictions().min_length = value;
}

template <typename T>
void xs_any_simple_type<T>::restrict_pattern(const std::string& value)
{
    this->restrictions().pattern.insert(value);
}

template <typename T>
void xs_any_simple_type<T>::restrict_total_digits(const size_t value)
{
    this->restrictions().total_digits = value;
}

template <typename T>
void xs_any_simple_type<T>::restrict_white_space(const white_space& value)
{
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

        switch (value)
        {
            case white_space::preserve:
            {
                // Do nothing
                break;
            }
            case white_space::replace:
            {
                white_space_replace(m_value);
                break;
            }
            case white_space::collapse:
            {
                white_space_collapse(m_value);
                break;
            }
        }
    }
}

template <typename T>
void xs_any_simple_type<T>::validate() const
{
    this->validate_enumeration();
    this->validate_fraction_digits();
    this->validate_length();
    this->validate_max_exclusive();
    this->validate_max_inclusive();
    this->validate_max_length();
    this->validate_min_exclusive();
    this->validate_min_inclusive();
    this->validate_min_length();
    this->validate_pattern();
    this->validate_total_digits();
    // There are no validation rules for whiteSpace
}

template <typename T>
std::string xs_any_simple_type<T>::to_string() const
{
    std::ostringstream ss;
    ss << this->value();
    return ss.str();
}

template <typename T>
void xs_any_simple_type<T>::validate_enumeration() const
{
    const auto enumeration = this->restrictions().enumeration;
    if (enumeration.empty())
    {
        return;
    }

    if (enumeration.find(this->value()) == enumeration.end())
    {
        throw std::runtime_error("validate_enumeration failed");
    }
}

template <typename T>
void xs_any_simple_type<T>::validate_fraction_digits() const
{
    const auto fraction_digits = this->restrictions().fraction_digits;
    if (!fraction_digits)
    {
        return;
    }

    // Only applies to floating point types
    if constexpr (std::is_floating_point_v<value_type>)
    {
        const auto order_of_magnitude = std::floor(std::log(std::abs(this->value())));

        if (order_of_magnitude < 0 && std::abs(order_of_magnitude) > fraction_digits.value())
        {
            throw std::runtime_error("restrict_fraction_digits failed - value too small");
        }
    }
}

template <typename T>
void xs_any_simple_type<T>::validate_length() const
{
    const auto length = this->restrictions().length;
    if (!length)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        if (this->value().length() != length.value())
        {
            throw std::runtime_error("restrict_length failed");
        }
    }
}

template <typename T>
void xs_any_simple_type<T>::validate_max_exclusive() const
{
    const auto max_exclusive = this->restrictions().max_exclusive;
    if (!max_exclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (this->value() >= max_exclusive.value())
        {
            throw std::runtime_error("restrict_max_exclusive failed");
        }
    }
}

template <typename T>
void xs_any_simple_type<T>::validate_max_inclusive() const
{
    const auto max_inclusive = this->restrictions().max_inclusive;
    if (!max_inclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (this->value() > max_inclusive.value())
        {
            throw std::runtime_error("restrict_max_inclusive failed");
        }
    }
}

template <typename T>
void xs_any_simple_type<T>::validate_max_length() const
{
    const auto max_length = this->restrictions().max_length;
    if (!max_length)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        if (this->value().length() > max_length.value())
        {
            throw std::runtime_error("restrict_max_length failed");
        }
    }
}

template <typename T>
void xs_any_simple_type<T>::validate_min_exclusive() const
{
    const auto min_exclusive = this->restrictions().min_exclusive;
    if (!min_exclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (this->value() <= min_exclusive.value())
        {
            throw std::runtime_error("restrict_min_exclusive failed");
        }
    }
}

template <typename T>
void xs_any_simple_type<T>::validate_min_inclusive() const
{
    const auto min_inclusive = this->restrictions().min_inclusive;
    if (!min_inclusive)
    {
        return;
    }

    // Only applies to string types
    if constexpr (!std::is_same_v<value_type, std::string>)
    {
        if (this->value() < min_inclusive.value())
        {
            throw std::runtime_error("restrict_min_inclusive failed");
        }
    }
}

template <typename T>
void xs_any_simple_type<T>::validate_min_length() const
{
    const auto min_length = this->restrictions().min_length;
    if (!min_length)
    {
        return;
    }

    // Only applies to string types
    if constexpr (std::is_same_v<value_type, std::string>)
    {
        if (this->value().length() < min_length.value())
        {
            throw std::runtime_error("restrict_min_length failed");
        }
    }
}

template <typename T>
void xs_any_simple_type<T>::validate_pattern() const
{
    const auto pattern = this->restrictions().pattern;
    if (pattern.empty())
    {
        return;
    }

    for (const auto& value : pattern)
    {
        auto xml = impl::xml::instance();
        if (xml.regex_match(this->to_string(), value))
        {
            // Match found, return!
            return;
        }
    }

    // No match found
    throw std::runtime_error("restrict_pattern failed");
}

template <typename T>
void xs_any_simple_type<T>::validate_total_digits() const
{
    const auto total_digits = this->restrictions().total_digits;
    if (!total_digits)
    {
        return;
    }

    // Only applies to numeric types
    if constexpr (std::is_arithmetic_v<value_type>)
    {
        const auto order_of_magnitude = [&] {
            // std::abs is not defined for unsigned types
            if constexpr (std::is_signed_v<value_type>)
            {
                return std::floor(std::log(std::abs(this->value())));
            }
            else
            {
                return std::floor(std::log(this->value()));
            }
        }();

        if (order_of_magnitude >= total_digits.value())
        {
            throw std::runtime_error("restrict_total_digits failed - value too large");
        }

        else if (order_of_magnitude < 0 && std::abs(order_of_magnitude) > total_digits.value())
        {
            throw std::runtime_error("restrict_total_digits failed - value too small");
        }
    }
}

// Explicit template declarations (this allows us to define the template functions in the .cpp file)
template class xs_any_simple_type<bool>;
template class xs_any_simple_type<char>;
template class xs_any_simple_type<double>;
template class xs_any_simple_type<float>;
template class xs_any_simple_type<int>;
template class xs_any_simple_type<long>;
template class xs_any_simple_type<long double>;
template class xs_any_simple_type<long long>;
template class xs_any_simple_type<short>;
template class xs_any_simple_type<std::string>;
template class xs_any_simple_type<unsigned char>;
template class xs_any_simple_type<unsigned int>;
template class xs_any_simple_type<unsigned long>;
template class xs_any_simple_type<unsigned long long>;
template class xs_any_simple_type<unsigned short>;

}  // namespace tnt::xsd
