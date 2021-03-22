#pragma once

#include "xml_string.hpp"

#include <libxml/xmlregexp.h>
#include <libxml/xmlstring.h>
#include <string>

namespace tnt::xsd::impl
{

class xml_regex final
{
public:
    xml_regex(const std::string& pattern);

    ~xml_regex();

    bool match(const xml_string& string);

private:
    xmlRegexp* m_regex;
};

}  // namespace tnt::xsd::impl
