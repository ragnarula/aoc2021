#include "gtest/gtest.h"
#include "day7/day7.h"

TEST(Day7, Part1Example)
{
    std::vector<std::string> input = { "16,1,2,0,4,2,7,1,2,14" };

    day7::Solution solution;

    auto result = solution.GetFirst(input);

    EXPECT_EQ(result, "37");
}

TEST(Day7, Part1)
{
    auto input = aoc::GetInputForDay("day7");
    day7::Solution solution;

    auto result = solution.GetFirst(input);

    EXPECT_EQ(result, "349357");

}

TEST(Day7, Part2Example)
{
    std::vector<std::string> input = { "16,1,2,0,4,2,7,1,2,14" };

    day7::Solution solution;

    auto result = solution.GetSecond(input);

    EXPECT_EQ(result, "168");
}