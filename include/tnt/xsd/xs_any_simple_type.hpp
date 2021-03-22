#pragma once

#include <optional>
#include <string>
#include <unordered_set>

namespace tnt::xsd
{

template <typename T>
class xs_any_simple_type
{
public:
    using value_type = T;

    value_type value() const;

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

    xs_any_simple_type(const value_type& value);

    void restrict_enumeration(const value_type& value);

    void restrict_fraction_digits(const size_t value);

    void restrict_length(const size_t value);

    void restrict_max_exclusive(const value_type& value);

    void restrict_max_inclusive(const value_type& value);

    void restrict_max_length(const size_t value);

    void restrict_min_exclusive(const value_type& value);

    void restrict_min_inclusive(const value_type& value);

    void restrict_min_length(const size_t value);

    void restrict_pattern(const std::string& value);

    void restrict_total_digits(const size_t value);

    void restrict_white_space(const white_space& value);

    void validate() const;

    virtual restriction_set& restrictions() = 0;

    virtual const restriction_set& restrictions() const = 0;

private:
    std::string to_string() const;

    void validate_enumeration() const;

    void validate_fraction_digits() const;

    void validate_length() const;

    void validate_max_exclusive() const;

    void validate_max_inclusive() const;

    void validate_max_length() const;

    void validate_min_exclusive() const;

    void validate_min_inclusive() const;

    void validate_min_length() const;

    void validate_pattern() const;

    void validate_total_digits() const;

    value_type m_value;
};

}  // namespace tnt::xsd
