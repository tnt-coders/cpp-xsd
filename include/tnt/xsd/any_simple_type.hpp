#pragma once

#include <optional>
#include <string>
#include <unordered_set>

namespace tnt::xsd
{

template <typename T>
class AnySimpleType
{
    friend class Restriction;

public:
    using value_type = T;

    explicit operator value_type() const;

protected:
    enum class WhiteSpace
    {
        preserve,
        replace,
        collapse,
    };

    class Restriction final
    {
    public:
        Restriction(AnySimpleType<value_type>* this_);

        void apply();

        std::unordered_set<value_type> enumeration() const;

        std::optional<size_t> fraction_digits() const;

        std::optional<size_t> length() const;

        std::optional<value_type> max_exclusive() const;

        std::optional<value_type> max_inclusive() const;

        std::optional<size_t> max_length() const;

        std::optional<value_type> min_exclusive() const;

        std::optional<value_type> min_inclusive() const;

        std::optional<size_t> min_length() const;

        std::unordered_set<std::string> pattern() const;

        std::optional<size_t> total_digits() const;

        std::optional<WhiteSpace> white_space() const;

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

    private:
        void apply_enumeration() const;

        void apply_fraction_digits() const;

        void apply_length() const;

        void apply_max_exclusive() const;

        void apply_max_inclusive() const;

        void apply_max_length() const;

        void apply_min_exclusive() const;

        void apply_min_inclusive() const;

        void apply_min_length() const;

        void apply_pattern() const;

        void apply_total_digits() const;

        void apply_white_space() const;

        std::unordered_set<value_type>  m_enumeration;
        std::optional<size_t>           m_fraction_digits;
        std::optional<size_t>           m_length;
        std::optional<value_type>       m_max_exclusive;
        std::optional<value_type>       m_max_inclusive;
        std::optional<size_t>           m_max_length;
        std::optional<value_type>       m_min_exclusive;
        std::optional<value_type>       m_min_inclusive;
        std::optional<size_t>           m_min_length;
        std::unordered_set<std::string> m_pattern;
        std::optional<size_t>           m_total_digits;
        std::optional<WhiteSpace>       m_white_space;

        AnySimpleType<value_type>* m_this;
    };

    AnySimpleType(const value_type& value);

private:
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
