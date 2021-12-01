#pragma once
#include "aoc/aoc.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace day1
{
    int CountIncreases(const std::vector<int>& input);

    class Solution : public aoc::ISolution
    {
    public:
        virtual std::string GetFirst(const std::vector<std::string>& input) override;
        virtual std::string GetSecond(const std::vector<std::string>& input) override;
    };
}