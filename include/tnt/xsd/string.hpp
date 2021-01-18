#pragma once

#include <string>

namespace tnt::xsd
{

class String
{
public:
    String(const std::string& data);

    virtual ~String() = default;

private:
    std::string m_data;
};

}