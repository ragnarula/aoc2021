#include "gtest/gtest.h"
#include "day6/day6.h"
#include "aoc/aoc.h"

TEST(Day6, SimulateSteps)
{
    std::vector<int> fish = {0};

    day6::Step(fish);

    EXPECT_EQ(fish.size(), 2);
    EXPECT_EQ(fish[0], 6);
    EXPECT_EQ(fish[1], 8);
}

TEST(Day6, Part1ExampleInt)
{
    std::vector<int> input = {3,4,3,1,2};

    for(int i = 0; i < 18; ++i)
    {
        day6::Step(input);
    }

    EXPECT_EQ(input, (std::vector<int>{6,0,6,4,5,6,0,1,1,2,6,0,1,1,1,2,2,3,3,4,6,7,8,8,8,8}));

    for(int i = 0; i < 80 - 18; ++i)
    {
        day6::Step(input);
    }

    EXPECT_EQ(input.size(), 5934);
}

TEST(Day6, Part1ExampleStr)
{
    std::vector<std::string> input = { "3,4,3,1,2" };
    day6::Solution solution;

    auto result = solution.GetFirst(input);
    EXPECT_EQ(result, "5934");
}

TEST(Day6, Part2ExampleStr)
{
    std::vector<std::string> input = { "3,4,3,1,2" };
    day6::Solution solution;

    auto result = solution.GetSecond(input);
    EXPECT_EQ(result, "26984457539");
}

TEST(Day6, Result)
{
    day6::Solution solution;
    auto input = aoc::GetInputForDay("day6");

    auto first = solution.GetFirst(input);
    auto second = solution.GetSecond(input);

    EXPECT_EQ(first, "349549");
    EXPECT_EQ(second, "1589590444365");
}