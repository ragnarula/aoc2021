#include "day3/day3.h"
#include "stringhelpers.h"
#include <array>
#include <bitset>

namespace day3
{
    static const size_t numBits = 12;

    std::bitset<numBits> GetMask(const size_t size)
    {
        std::bitset<numBits> mask;
        for(int i = 0; i < size; ++i)
        {
            mask.set(i);
        }
        return mask;
    }

    std::string Solution::GetFirst(const std::vector<std::string>& input) 
    {
        const auto mask = GetMask(input[0].size());

        std::vector<std::bitset<numBits>> bits;
        std::transform(input.begin(), input.end(), std::back_inserter(bits), [](const auto& elem) {
            return std::bitset<numBits>(elem);
        });

        const auto majorities = GetMajorities(bits);

        unsigned long gamma = majorities.to_ulong();
        unsigned long epsilon = ((~majorities) & mask).to_ulong();
        
        return std::to_string(gamma * epsilon);
    }
    
    std::string Solution::GetSecond(const std::vector<std::string>& input) 
    {
        const size_t wordsize = input[0].size();
        const auto mask = GetMask(wordsize);

        std::vector<std::bitset<numBits>> bits;
        std::transform(input.begin(), input.end(), std::back_inserter(bits), [](const auto& elem) {
            return std::bitset<numBits>(elem);
        });

        const auto oxygen = (FilterByCriteria(bits, wordsize, MostCommon) & mask).to_ulong();
        const auto co2 = (FilterByCriteria(bits, wordsize, LeastCommon) & mask).to_ulong();

        return std::to_string(oxygen * co2);
    }
}