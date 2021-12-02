#pragma once
#include "aoc/aoc.h"

namespace day2
{
    int GetUnits(const std::string& command);
    
    class Solution : public aoc::ISolution
    {
    public:
        virtual std::string GetFirst(const std::vector<std::string>& input) override;
        virtual std::string GetSecond(const std::vector<std::string>& input) override;
    };
}