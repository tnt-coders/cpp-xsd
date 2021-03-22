#include "xml_string.hpp"

#include <libxml/xmlstring.h>
#include <string>

namespace tnt::xsd::impl
{

xml_string::xml_string(const std::string& string)
{
    m_string = xmlCharStrdup(string.c_str());
}

xml_string::~xml_string()
{
    free(m_string);
}

xml_string::operator xmlChar*() const
{
    return m_string;
}

}  // namespace tnt::xsd::impl
