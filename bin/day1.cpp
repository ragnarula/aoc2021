#include "solution.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "day1/day1.h"

namespace solution
{
    std::string first(const std::vector<std::string>& input)
    {
        std::vector<int> ints(input.size());
        std::transform(input.begin(), input.end(), ints.begin(), [](auto& elem) -> int { return std::stoi(elem);});
        auto result = day1::CountIncreases(ints);

        return std::to_string(result);
    }
    
    std::string second(const std::vector<std::string>& input)
    {
        return "World!";
    }
}