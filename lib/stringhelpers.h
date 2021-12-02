#pragma once
#include <vector>
#include <string>

namespace aoc
{
std::vector<std::string> Tokenize(std::string input, std::string delim);
bool HasPrefix(const std::string& str, const std::string& prefix);
}
