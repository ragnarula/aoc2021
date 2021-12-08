#include "day7/day7.h"
#include "stringhelpers.h"
#include <unordered_map>


namespace day7
{
    std::string Solution::GetFirst(const std::vector<std::string>& input) 
    {
        auto nums = aoc::Tokenize(input[0], ",");
        std::vector<int> ints;
        std::transform(nums.begin(), nums.end(), std::back_inserter(ints), [](const auto& elem) { return std::stoi(elem);});

        int max = 0;
        for(int elem : ints)
        {
            max = std::max(max, elem);
        }

        int min = INT_MAX;
        for(int i = 0; i <= max; ++i)
        {
            int sum = 0;
            for(int elem : ints)
            {
                sum += std::abs(i - elem);
            }

            min = std::min(min, sum);
        }

        return std::to_string(min);
    }

    std::string Solution::GetSecond(const std::vector<std::string>& input)
    {
        auto nums = aoc::Tokenize(input[0], ",");
        std::vector<int> ints;
        std::transform(nums.begin(), nums.end(), std::back_inserter(ints), [](const auto& elem) { return std::stoi(elem);});

        int max = 0;
        for(int elem : ints)
        {
            max = std::max(max, elem);
        }

        std::unordered_map<int, int> counts;
        for(int elem : ints)
        {
            counts[elem] += 1;
        }

        int min = INT_MAX;
        for(int i = 0; i <= max; ++i)
        {
            int sum = 0;
            for(int elem : ints)
            {
                const int distance = std::abs(i - elem);
                const int cost = (distance * (distance + 1)) / 2;
                sum += cost;
            }

            min = std::min(min, sum);
        }

        return std::to_string(min);
    }
}