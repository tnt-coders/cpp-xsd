#pragma once

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iomanip>
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
class xs_any_simple_type
{
public:
    using value_type = T;

    value_type value() const
    {
        return m_value;
    }

protected:
    enum class white_space
    {
        preserve,
        replace,
        collapse,
    };

    struct restriction_set final
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
        std::optional<white_space>      white_space;
    };

    xs_any_simple_type(const value_type& value)
        : m_value(value)
    {}

    void restrict_enumeration(const value_type& value)
    {
        this->restrictions().enumeration.insert(value);
    }

    void restrict_fraction_digits(const size_t value)
    {
        this->restrictions().fraction_digits = value;
    }

    void restrict_length(const size_t value)
    {
        this->restrictions().length = value;
    }

    void restrict_max_exclusive(const value_type& value)
    {
        this->restrictions().max_exclusive = value;
    }

    void restrict_max_inclusive(const value_type& value)
    {
        this->restrictions().max_inclusive = value;
    }

    void restrict_max_length(const size_t value)
    {
        this->restrictions().max_length = value;
    }

    void restrict_min_exclusive(const value_type& value)
    {
        this->restrictions().min_exclusive = value;
    }

    void restrict_min_inclusive(const value_type& value)
    {
        this->restrictions().min_inclusive = value;
    }

    void restrict_min_length(const size_t value)
    {
        this->restrictions().min_length = value;
    }

    void restrict_pattern(const std::string& value)
    {
        this->restrictions().pattern.insert(value);
    }

    void restrict_total_digits(const size_t value)
    {
        this->restrictions().total_digits = value;
    }

    void restrict_white_space(const white_space& value)
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
        // There are no validation rules for whiteSpace
    }

protected:
    virtual restriction_set& restrictions() = 0;

    virtual const restriction_set& restrictions() const = 0;

private:
    std::string to_string() const
    {
        std::ostringstream ss;
        ss << this->value();
        return ss.str();
    }

    void validate_enumeration() const
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

    void validate_fraction_digits() const
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
                // TODO: simply return here
                valid = true;
            }
        }

        if (!valid)
        {
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

    value_type m_value;
};

}  // namespace tnt::xsd
