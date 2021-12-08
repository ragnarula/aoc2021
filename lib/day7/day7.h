#pragma once
#include "aoc/aoc.h"
#include <string>
#include <vector>
#include <algorithm>

namespace day7
{
    class Solution : public aoc::ISolution
    {
    public:
        virtual std::string GetFirst(const std::vector<std::string>& input) override;
        virtual std::string GetSecond(const std::vector<std::string>& input) override;
    };
}