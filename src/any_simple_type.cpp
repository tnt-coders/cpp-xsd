#include "any_simple_type.hpp"

#include <boost/algorithm/string/trim.hpp>
#include <cassert>
#include <iostream>
#include <regex>
#include <string>
#include <type_traits>

namespace tnt::xsd
{

void white_space_replace(std::string* s);
void white_space_collapse(std::string* s);

template <typename T>
AnySimpleType<T>::~AnySimpleType() = default;

template <typename T>
AnySimpleType<T>::operator T() const
{
    return m_value;
}

template <typename T>
AnySimpleType<T>::AnySimpleType(const T& value)
    : m_value(value)
{
    this->validate();
}

template <typename T>
void AnySimpleType<T>::length(const size_t value)
{
    if (value == 0)
    {
        // TODO: Better error message
        throw std::runtime_error("Invalid value provided for 'length'");
    }

    m_length = value;
}

template <typename T>
void AnySimpleType<T>::enumeration(const T& value)
{
    m_enumeration.insert(value);
}

template <typename T>
void AnySimpleType<T>::pattern(const std::string& value)
{
    m_pattern.insert(value);
}

template <typename T>
void AnySimpleType<T>::white_space(const facet::WhiteSpace& value)
{
    // Any type that is not a string will be automatically collapsed by the C++ type system
    if constexpr (std::is_same_v<T, std::string>)
    {
        switch (value)
        {
            case facet::WhiteSpace::preserve:
            {
                // Do nothing
                break;
            }
            case facet::WhiteSpace::replace:
            {
                white_space_replace(&m_value);
                break;
            }
            case facet::WhiteSpace::collapse:
            {
                white_space_collapse(&m_value);
            }
        }
    }
}

template <typename T>
void AnySimpleType<T>::validate()
{
    this->validate_length();
    this->validate_enumeration();
    this->validate_pattern();

    // TODO: finish implementation
    std::cerr << "WARNING: implementation of validate is incomplete." << std::endl;
}

template <typename T>
void AnySimpleType<T>::validate_length()
{
    if constexpr (std::is_same_v<T, std::string>)
    {
        if (!m_length)
        {
            return;
        }

        if (m_value.length() != m_length)
        {
            // TODO: Better error message
            throw std::runtime_error("validate_length failed");
        }

        // Clear the length so it doesn't get processed multiple times
        m_length.reset();
    }
}

template <typename T>
void AnySimpleType<T>::validate_enumeration()
{
    if (m_enumeration.empty())
    {
        return;
    }

    if (m_enumeration.find(m_value) == m_enumeration.end())
    {
        // TODO: better error message
        throw std::runtime_error("validate_enumeration failed");
    }

    // Clear the enumerations so they don't get processed multiple times
    m_enumeration.clear();
}

template <typename T>
void AnySimpleType<T>::validate_pattern()
{
    if (m_pattern.empty())
    {
        return;
    }

    // TODO: look for a more elegant way to convert to string
    std::string value_as_string{};
    if constexpr (std::is_same_v<T, std::string>)
    {
        value_as_string = m_value;
    }
    else
    {
        value_as_string = std::to_string(m_value);
    }

    bool valid = false;
    for (const auto& value : m_pattern)
    {
        std::regex rx(value);
        if (std::regex_match(value_as_string, rx))
        {
            valid = true;
        }
    }

    // Clear the patterns so they don't get processed multiple times
    m_pattern.clear();

    if (!valid)
    {
        // TODO: Better error message
        throw std::runtime_error("validate_pattern failed");
    }
}

// Explicit template declarations (this allows us to define the template functions in the .cpp file)
template class AnySimpleType<double>;
template class AnySimpleType<long double>;
template class AnySimpleType<std::string>;

void white_space_replace(std::string* s)
{
    // Replace tab, carriage return, and line feed characters with spaces
    std::regex rx("\\t|\\r|\\n");
    *s = std::regex_replace(*s, rx, " ");
}

void white_space_collapse(std::string* s)
{
    // Perform WhiteSpace::replace function first
    white_space_replace(s);

    // Replace contiguous sequences of spaces with a single space
    std::regex rx("\\s+");
    *s = std::regex_replace(*s, rx, " ");

    // Trim leading and trailing whitespace
    boost::algorithm::trim(*s);
}

}  // namespace tnt::xsd
