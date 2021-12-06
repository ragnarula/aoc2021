#pragma once
#include "aoc/aoc.h"

#include <string>
#include <vector>

namespace day6
{
    class Solution : public aoc::ISolution
    {
    public:
        virtual std::string GetFirst(const std::vector<std::string>& input) override;
        virtual std::string GetSecond(const std::vector<std::string>& input) override;
    };
}