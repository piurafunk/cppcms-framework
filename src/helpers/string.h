#pragma once

#include <string>
#include <vector>
#include <map>

std::string url_encode(const std::string &);
std::string url_decode(const std::string &);
template <typename Out>
void split(const std::string &, char, Out);
std::vector<std::string> split(const std::string &, char);
std::map<std::string, std::string> parseQueryString(const std::string &);
void reverse(std::string&);