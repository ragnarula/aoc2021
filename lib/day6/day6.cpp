#include "day6/day6.h"
#include "stringhelpers.h"
#include <array>

namespace day6
{
    void Step(std::vector<int>& fish) 
    {
        std::vector<int> newFish;
        newFish.reserve(fish.size());

        for(auto& elem : fish)
        {
            if(elem == 0)
            {
                elem = 6;
                newFish.push_back(8);
            }
            else
            {
                --elem;
            }
        }
        fish.reserve(newFish.size());
        fish.insert(fish.end(), newFish.begin(), newFish.end());
    }

    
    std::string Solution::GetFirst(const std::vector<std::string>& input) 
    {
        auto line = input[0];
        auto nums = aoc::Tokenize(line, ",");

        std::vector<int> fish;
        fish.reserve(nums.size());

        std::transform(nums.begin(), nums.end(), std::back_inserter(fish), [](const auto& elem){ return std::stoi(elem);});

        for(int i = 0; i < 80; ++i)
        {
            Step(fish);
        }

        return std::to_string(fish.size());
    }

    std::string Solution::GetSecond(const std::vector<std::string>& input)
    {
        auto line = input[0];
        auto nums = aoc::Tokenize(line, ",");

        std::vector<int> fish;
        fish.reserve(nums.size());

        std::transform(nums.begin(), nums.end(), std::back_inserter(fish), [](const auto& elem){ return std::stoi(elem);});

        std::array<long int, 9> counts{0};
        for(int i : fish)
        {
            counts[i] += 1;
        }

        for(int i = 0; i < 256; ++i)
        {
            long int newfish = counts[0];
            counts[0] = counts[1];
            counts[1] = counts[2];
            counts[2] = counts[3];
            counts[3] = counts[4];
            counts[4] = counts[5];
            counts[5] = counts[6];
            counts[6] = counts[7] + newfish;
            counts[7] = counts[8];
            counts[8] = newfish;
        }

        long int sum = 0;
        for(long int elem : counts)
        {
            sum += elem;
        }

        return std::to_string(sum);
    }
}