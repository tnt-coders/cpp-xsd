#pragma once

#include <libxml/xmlstring.h>
#include <string>

namespace tnt::xsd::impl
{

class xml_string final
{
public:
    xml_string(const std::string& string);

    ~xml_string();

    explicit operator xmlChar*() const;

private:
    xmlChar* m_string;
};

}  // namespace tnt::xsd::impl
