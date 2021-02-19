#pragma once

#include <optional>
#include <string>
#include <typeindex>
#include <unordered_set>

namespace tnt::xsd
{

template <typename T>
class AnySimpleType
{
public:
    using value_type = T;

    std::string to_string() const {}

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

    virtual Restrictions restrictions() const = 0;

    virtual void restrictions(const Restrictions& restrictions) = 0;

    AnySimpleType(const value_type& value);

    void enumeration(const value_type& value);

    void fraction_digits(const size_t value, const bool fixed = false);

    void length(const size_t value, const bool fixed = false);

    void max_exclusive(const value_type& value, const bool fixed = false);

    void max_inclusive(const value_type& value, const bool fixed = false);

    void max_length(const size_t value, const bool fixed = false);

    void min_exclusive(const value_type& value, const bool fixed = false);

    void min_inclusive(const value_type& value, const bool fixed = false);

    void min_length(const size_t value, const bool fixed = false);

    void pattern(const std::string& value);

    void total_digits(const size_t value, const bool fixed = false);

    void white_space(const WhiteSpace& value, const bool fixed = false);

    void validate() const;

private:
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

    void validate_white_space() const;

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
