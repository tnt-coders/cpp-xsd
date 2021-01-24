#pragma once

#include <memory>
#include <optional>
#include <regex>
#include <unordered_set>
#include <vector>

namespace tnt::xsd
{

// Forward declare facet::WhiteSpace
namespace facet
{

enum class WhiteSpace
{
    preserve,
    replace,
    collapse,
};

}  // namespace facet

template <typename T>
class AnySimpleType
{
public:
    virtual ~AnySimpleType() = 0;

    explicit operator T() const;

protected:
    AnySimpleType(const T& value);

    void length(const size_t value);

    void enumeration(const T& value);

    void pattern(const std::string& value);

    void white_space(const facet::WhiteSpace& value);

    void validate();

private:
    void validate_length();
    void validate_enumeration();
    void validate_pattern();

    std::optional<size_t>           m_length;
    std::unordered_set<T>           m_enumeration;
    std::unordered_set<std::string> m_pattern;

    T m_value;
};

}  // namespace tnt::xsd
