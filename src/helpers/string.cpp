#include <sstream>
#include <iomanip>
#include <cctype>
#include <bits/stdc++.h>

#include <iostream>

#include "string.h"

std::string url_decode(const std::string &value)
{
    std::ostringstream decoded;
    std::stringstream ss;
    unsigned int hex;
    std::string s;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i)
    {
        std::string::value_type c = (*i);

        switch (c) {
            case '+':
                decoded << ' ';
                break;
            case '%':
                s = std::string(1, *(i+1)) + std:: string(1, *(i+2));
                ss << std::hex << s;
                ss >> hex;
                decoded << (unsigned char)hex;
                ss.clear();
                i+=2;
                break;
            default:
                decoded << c;
        }
    }

    return decoded.str();
}

std::string url_encode(const std::string &value)
{
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i)
    {
        std::string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
        {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char)c);
        escaped << std::nouppercase;
    }

    return escaped.str();
}

template <typename Out>
void split(const std::string &s, char delim, Out result)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elements;
    split(s, delim, std::back_inserter(elements));
    return elements;
}

std::map<std::string, std::string> parseQueryString(const std::string &s)
{
    std::vector<std::string> v = split(s, '&');
    std::map<std::string, std::string> map;
    for (const std::string &s : v)
    {
        std::vector<std::string> parameter = split(s, '=');
        map.insert(std::pair<std::string, std::string>(parameter[0], url_decode(parameter[1])));
    }

    return map;
}

void reverse(std::string &s)
{
    std::reverse(s.begin(), s.end());
}
