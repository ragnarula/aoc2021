#include "gtest/gtest.h"
#include "day1/day1.h"

TEST(Day1, CountsIncreases) {
    std::vector<int> input { 1, 2, 3, 1, 5, 4, 7};

    ASSERT_EQ(day1::CountIncreases(input), 4);
}

TEST(Day1, CorrectResultPart1)
{
    aoc::Register("day1", [](){ return std::make_unique<day1::Solution>(); });
    auto [first, second] = aoc::GetSolutionForDay("day1");
    
    ASSERT_EQ(first, "1583");
}

TEST(Day1, CorrectResultPart2)
{
    aoc::Register("day1", [](){ return std::make_unique<day1::Solution>(); });
    auto [first, second] = aoc::GetSolutionForDay("day1");
    
    ASSERT_EQ(second, "1627");
}