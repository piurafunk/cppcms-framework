#pragma once

#include <map>
#include <string>

#include <cppcms/json.h>

namespace cppcms
{
namespace json
{
template <>
struct traits<std::map<std::string, std::string>>
{
    static void set(value &v, std::map<std::string, std::string> const &map)
    {
        for (auto parameter : map)
        {
            v[parameter.first] = parameter.second;
        }
    }

    static std::map<std::string, std::string> get(value const &v)
    {
        return std::map<std::string, std::string>();
    }
};
} // namespace json
} // namespace cppcms
