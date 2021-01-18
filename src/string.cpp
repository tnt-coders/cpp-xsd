#include "string.hpp"

#include <string>
#include <boost/regex/icu.hpp>

//#include <iostream>

namespace tnt::xsd
{

//std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

String::String(const std::string& data)
    : m_data(data)
{
    /*std::wregex rx(L"(\x9|\xA|\xD|[\x20-\xD7FF]|[\xE000-\xFFFD]|[\x10000-\x10FFFF])+");
    bool test = std::regex_match(converter.from_bytes(data), rx);
    std::locale::global(std::locale());
    std::cout << "TEST: " << test << std::endl;*/
}

} // namespace tnt::xsd