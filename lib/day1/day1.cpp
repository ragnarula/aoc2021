#include "day1/day1.h"

namespace day1
{
    int CountIncreases(const std::vector<int>& input)
    {
        int increases = 0;

        for(int i = 0; i < input.size(); ++i)
        {
            if(i > 0)
            {
                if(input[i] > input[i - 1])
                {
                    ++increases;
                }
            }
        }

        return increases;
    }
    
    std::string Solution::GetFirst(const std::vector<std::string>& input) 
    {
        std::vector<int> ints(input.size());
        std::transform(input.begin(), input.end(), ints.begin(), [](auto& elem) -> int { return std::stoi(elem);});
        auto result = day1::CountIncreases(ints);
        return std::to_string(result);
    }
    std::string Solution::GetSecond(const std::vector<std::string>& input)
    {
        std::vector<int> ints(input.size());
        std::transform(input.begin(), input.end(), ints.begin(), [](auto& elem) -> int { return std::stoi(elem);});
        
        std::vector<std::tuple<int, int, int>> windows; 
        for(int i = 0; i < (int)ints.size() - 2; ++i)
        {
            windows.push_back({ints[i], ints[i + 1], ints[i + 2]});
        }

        std::vector<int> summed(windows.size());
        std::transform(windows.begin(), windows.end(), summed.begin(), [](auto& elem){
            auto [a, b, c] = elem;
            return a + b + c;
        });

        auto result = day1::CountIncreases(summed);
        return std::to_string(result);
    }
}