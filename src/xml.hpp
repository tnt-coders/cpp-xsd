#pragma once

#include <string>

namespace tnt::xsd::impl
{

class xml final
{
public:
    // Unfortunately a singleton needs to be used because the only purpose of this class is to setup
    // and cleanup the libxml2 library. This should only be done once per program.
    static xml& instance();

    bool regex_match(const std::string& string, const std::string& regex) const;

private:
    xml();
};

}  // namespace tnt::xsd::impl
