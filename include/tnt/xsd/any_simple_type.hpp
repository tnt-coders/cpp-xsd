#pragma once

#include <optional>
#include <regex>
#include <string>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

namespace tnt::xsd
{

template <typename T>
class AnySimpleType
{
public:
    using value_type = T;

    std::string to_string() const
    {
        if constexpr (std::is_same_v<value_type, std::string>)
        {
            return m_value;
        }

        // TODO: Convert the value to a string
        //       Numeric types should round properly
        //       Boolean should match pattern restriction
        else
        {
            return std::to_string(m_value);
        }
    }

    value_type value() const
    {
        return m_value;
    }

protected:
    enum class WhiteSpace
    {
        preserve,
        replace,
        collapse,
    };

    struct Restrictions final
    {
        std::unordered_set<value_type>  enumeration;
        std::optional<size_t>           fraction_digits;
        std::optional<size_t>           length;
        std::optional<value_type>       max_exclusive;
        std::optional<value_type>       max_inclusive;
        std::optional<size_t>           max_length;
        std::optional<value_type>       min_exclusive;
        std::optional<value_type>       min_inclusive;
        std::optional<size_t>           min_length;
        std::unordered_set<std::string> pattern;
        std::optional<size_t>           total_digits;
        std::optional<WhiteSpace>       white_space;
    };

    AnySimpleType(const value_type& value)
        : m_value(value)
    {}

    void enumeration(const value_type& value)
    {
        this->restrictions().enumeration.insert(value);
    }

    void fraction_digits(const size_t value, const bool fixed = false)
    {
        if (m_fraction_digits_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'fractionDigits'");
        }

        m_fraction_digits_fixed = fixed;

        this->restrictions().fraction_digits = value;
    }

    void length(const size_t value, const bool fixed = false)
    {
        if (m_length_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'length'");
        }

        m_length_fixed = fixed;

        this->restrictions().length = value;
    }

    void max_exclusive(const value_type& value, const bool fixed = false)
    {
        if (m_max_exclusive_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'maxExclusive'");
        }

        m_max_exclusive_fixed = fixed;

        this->restrictions().max_exclusive = value;
    }

    void max_inclusive(const value_type& value, const bool fixed = false)
    {
        if (m_max_inclusive_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'maxInclusive'");
        }

        m_max_inclusive_fixed = fixed;

        this->restrictions().max_inclusive = value;
    }

    void max_length(const size_t value, const bool fixed = false)
    {
        if (m_max_length_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'maxLength'");
        }

        m_max_length_fixed = fixed;

        this->restrictions().max_length = value;
    }

    void min_exclusive(const value_type& value, const bool fixed = false)
    {
        if (m_min_exclusive_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'minExclusive'");
        }

        m_min_exclusive_fixed = fixed;

        this->restrictions().min_exclusive = value;
    }

    void min_inclusive(const value_type& value, const bool fixed = false)
    {
        if (m_min_inclusive_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'minInclusive'");
        }

        m_min_inclusive_fixed = fixed;

        this->restrictions().min_inclusive = value;
    }

    void min_length(const size_t value, const bool fixed = false)
    {
        if (m_min_length_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'minLength'");
        }

        m_min_length_fixed = fixed;

        this->restrictions().min_length = value;
    }

    void pattern(const std::string& value)
    {
        this->restrictions().pattern.insert(value);
    }

    void total_digits(const size_t value, const bool fixed = false)
    {
        if (m_total_digits_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'totalDigits'");
        }

        m_total_digits_fixed = fixed;

        this->restrictions().total_digits = value;
    }

    void white_space(const WhiteSpace& value, const bool fixed = false)
    {
        if (m_white_space_fixed)
        {
            throw std::runtime_error("Cannot restrict fixed 'whiteSpace'");
        }

        m_white_space_fixed = fixed;

        this->restrictions().white_space = value;
    }

    void validate() const
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
        this->validate_white_space();
    }

private:
    void validate_enumeration() const
    {
        const auto enumeration = this->restrictions().enumeration;
        if (enumeration.empty())
        {
            return;
        }

        if (enumeration.find(this->value()) == enumeration.end())
        {
            // TODO: better error message
            throw std::runtime_error("validate_enumeration failed");
        }
    }

    void validate_fraction_digits() const
    {
        const auto fraction_digits = this->restrictions().fraction_digits;
        if (!fraction_digits)
        {
            return;
        }

        if constexpr (std::is_floating_point_v<value_type>)
        {
            const auto order_of_magnitude = std::floor(std::log(std::abs(this->value())));

            if (order_of_magnitude < 0 && std::abs(order_of_magnitude) > fraction_digits.value())
            {
                throw std::runtime_error("restrict_fraction_digits failed - value too small");
            }

            // TODOTODOTODO
            //
            // TODO: This rounding should occur when printing to an xml file (converting to a
            // string)
            // TODO: This should not be checked during validation
            //
            // Also use iomanip to set proper precision for printing
            //
            // TODOTODOTODO
            // const auto scale = std::pow(10, this->restrictions().fraction_digits.value());
            // m_simple_type->value = std::round(m_simple_type->value * scale) / scale;
        }
    }

    void validate_length() const
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
                // TODO: Better error message
                throw std::runtime_error("restrict_length failed");
            }
        }
    }

    void validate_max_exclusive() const
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
                // TODO: Better error message
                throw std::runtime_error("restrict_max_exclusive failed");
            }
        }
    }

    void validate_max_inclusive() const
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
                // TODO: Better error message
                throw std::runtime_error("restrict_max_inclusive failed");
            }
        }
    }

    void validate_max_length() const
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
                // TODO: Better error message
                throw std::runtime_error("restrict_max_length failed");
            }
        }
    }

    void validate_min_exclusive() const
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
                // TODO: Better error message
                throw std::runtime_error("restrict_min_exclusive failed");
            }
        }
    }

    void validate_min_inclusive() const
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
                // TODO: Better error message
                throw std::runtime_error("restrict_min_inclusive failed");
            }
        }
    }

    void validate_min_length() const
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
                // TODO: Better error message
                throw std::runtime_error("restrict_min_length failed");
            }
        }
    }

    void validate_pattern() const
    {
        const auto pattern = this->restrictions().pattern;
        if (pattern.empty())
        {
            return;
        }

        bool valid = false;
        for (const auto& value : pattern)
        {
            const std::regex rx(value);
            if (std::regex_match(this->to_string(), rx))
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

    void validate_total_digits() const
    {
        const auto total_digits = this->restrictions().total_digits;
        if (!total_digits)
        {
            return;
        }

        // Only applies to numeric types
        if constexpr (std::is_arithmetic_v<value_type>)
        {
            const auto order_of_magnitude = std::floor(std::log(std::abs(this->value())));

            if (order_of_magnitude >= total_digits.value())
            {
                throw std::runtime_error("restrict_total_digits failed - value too large");
            }

            else if (order_of_magnitude < 0 && std::abs(order_of_magnitude) > total_digits.value())
            {
                throw std::runtime_error("restrict_total_digits failed - value too small");
            }

            // TODOTODOTODO
            //
            // TODO: This rounding should occur when printing to an xml file (converting to a
            // string)
            // TODO: This should not be checked during validation
            //
            // Also use iomanip to set proper precision for printing
            //
            // TODOTODOTODO
            // const auto scale = std::pow(10, m_total_digits.value() -
            // std::floor(std::log(m_simple_type->value)) - 1);
            // m_simple_type->value = std::round(m_simple_type->value * scale) / scale;
        }
    }

    void validate_white_space() const
    {
        // if (!m_white_space)
        //{
        //    return;
        //}

        //// Only applies to string types
        // if constexpr (std::is_same_v<value_type, std::string>)
        //{
        //    constexpr auto white_space_replace = [](std::string& value) {
        //        std::regex rx("\\t|\\r|\\n");
        //        value = std::regex_replace(value, rx, " ");
        //    };

        //    constexpr auto white_space_collapse = [white_space_replace](std::string& value) {
        //        white_space_replace(value);

        //        std::regex rx("\\s+");
        //        value = std::regex_replace(value, rx, " ");

        //        boost::algorithm::trim(value);
        //    };

        //    switch (m_white_space.value())
        //    {
        //        case WhiteSpace::preserve:
        //        {
        //            // Do nothing
        //            break;
        //        }
        //        case WhiteSpace::replace:
        //        {
        //            white_space_replace(m_simple_type->value);
        //            break;
        //        }
        //        case WhiteSpace::collapse:
        //        {
        //            white_space_collapse(m_simple_type->value);
        //            break;
        //        }
        //    }
        //}
    }

    Restrictions& restrictions()
    {
        return m_restrictions[typeid(*this)];
    }

    const Restrictions& restrictions() const
    {
        return m_restrictions.at(typeid(*this));
    }

    std::unordered_map<std::type_index, Restrictions> m_restrictions;

    bool m_fraction_digits_fixed = false;
    bool m_length_fixed          = false;
    bool m_max_exclusive_fixed   = false;
    bool m_max_inclusive_fixed   = false;
    bool m_max_length_fixed      = false;
    bool m_min_exclusive_fixed   = false;
    bool m_min_inclusive_fixed   = false;
    bool m_min_length_fixed      = false;
    bool m_total_digits_fixed    = false;
    bool m_white_space_fixed     = false;

    value_type m_value;
};

}  // namespace tnt::xsd
