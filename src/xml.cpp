#include "xml.hpp"

#include "xml_regex.hpp"
#include "xml_string.hpp"

#include <libxml/globals.h>
#include <string>

namespace tnt::xsd::impl
{

xml& xml::instance()
{
    static xml instance;
    return instance;
}

bool xml::regex_match(const std::string& string, const std::string& pattern) const
{
    xml_string xml_string(string);
    xml_regex  xml_regex(pattern);
    return xml_regex.match(xml_string);
}

xml::xml()
{
    LIBXML_TEST_VERSION;
}

}  // namespace tnt::xsd::impl
