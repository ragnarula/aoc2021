
#pragma once
#include "aoc/aoc.h"
#include <vector>
#include <bitset>

namespace day3
{    
    template<size_t N>
    std::bitset<N> GetMajorities(const std::vector<std::bitset<N>>& input, const bool tie = true);

    enum ECriteria
    {
        MostCommon,
        LeastCommon
    };

    template<size_t N>
    std::bitset<N> FilterByCriteria(const std::vector<std::bitset<N>>& input, size_t wordSize, day3::ECriteria Criteria);

    class Solution : public aoc::ISolution
    {
    public:
        virtual std::string GetFirst(const std::vector<std::string>& input) override;
        virtual std::string GetSecond(const std::vector<std::string>& input) override;
    };
}

template<size_t N>
std::bitset<N> day3::GetMajorities(const std::vector<std::bitset<N>>& input, const bool tie) 
{
    std::array<int, N> counters{0};
    for(const auto& elem : input)
    {
        for(size_t i = 0; i < N; ++i)
        {
            counters[i] += elem[i] ? 1 : -1;
        }
    }

    std::bitset<N> majorities;
    for(size_t i = 0; i < N; ++i)
    {
        const bool majority = counters[i] > 0 ? 1 : 0;
        majorities[i] = counters[i] == 0 ? tie : majority;
    }  
    return majorities;
}

template<size_t N>
std::bitset<N> day3::FilterByCriteria(const std::vector<std::bitset<N>>& input, size_t wordsize, day3::ECriteria criteria) 
{
    std::vector<std::bitset<N>> source = input;
    std::vector<std::bitset<N>> dest;
    dest.reserve(source.size());

    for(int i = wordsize - 1; i >= 0; --i)
    {
        const auto majorities = GetMajorities(source);
        const bool desiredBit = criteria == MostCommon ? majorities[i] : !majorities[i];

        std::copy_if(source.begin(), source.end(), std::back_inserter(dest), [desiredBit, i](const auto& elem){
            return elem[i] == desiredBit;
        });

        if(dest.size() == 1)
        {
            break;
        }

        std::swap(source, dest);
        dest.clear();
    }
    
    if(dest.size() == 1)
    {
        return dest[0];
    }
    return {};
}