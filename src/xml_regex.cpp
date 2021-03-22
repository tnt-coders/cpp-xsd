#include "xml_regex.hpp"

#include "xml_string.hpp"

#include <libxml/xmlstring.h>
#include <sstream>
#include <string>

namespace tnt::xsd::impl
{

xml_regex::xml_regex(const std::string& pattern)
{
    xml_string xml_string(pattern);
    m_regex = xmlRegexpCompile(static_cast<xmlChar*>(xml_string));
    if (m_regex == nullptr)
    {
        std::ostringstream error;
        error << "Failed to compile xml regular expression: '" << pattern << "'";
        throw std::runtime_error(error.str());
    }
}

xml_regex::~xml_regex()
{
    free(m_regex);
}

bool xml_regex::match(const xml_string& string)
{
    LIBXML_TEST_VERSION;

    const auto match = xmlRegexpExec(m_regex, static_cast<xmlChar*>(string));
    if (match == 1)
    {
        return true;
    }
    else if (match == 0)
    {
        return false;
    }
    else
    {
        // TODO: better error (does libxml2 have a way to translate errors into strings?)
        std::ostringstream error;
        error << "Error returned by libxml2 xmlRegexpExec: " << match;
        throw std::runtime_error(error.str());
    }
}

}  // namespace tnt::xsd::impl
