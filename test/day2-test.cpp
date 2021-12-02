#include <vector>
#include <string>

#include "gtest/gtest.h"
#include "day2/day2.h"
#include "aoc/aoc.h"

TEST(Day2, Part1Example)
{
    std::vector<std::string> input = {
        "forward 5",
        "down 5",
        "forward 8",
        "up 3",
        "down 8",
        "forward 2"
    };

    day2::Solution solution;
    auto result = solution.GetFirst(input);
    EXPECT_EQ(result, "150");
}

TEST(GetUnits, ReturnsTheNumberOfUnitsFromTheCommandLine)
{
    std::string command("forward 10");
    auto result = day2::GetUnits(command);
    EXPECT_EQ(result, 10);
}

TEST(Day2, Part1)
{
    REGISTER(day2, day2::Solution);
    auto [first, second] = aoc::GetSolutionForDay("day2");
    
    EXPECT_EQ(first, "1924923");
}

TEST(Day2, Part2Example)
{
    std::vector<std::string> input = {
        "forward 5",
        "down 5",
        "forward 8",
        "up 3",
        "down 8",
        "forward 2"
    };

    day2::Solution solution;
    auto result = solution.GetSecond(input);
    EXPECT_EQ(result, "900");
}

TEST(Day2, Part2)
{
    REGISTER(day2, day2::Solution);
    auto [first, second] = aoc::GetSolutionForDay("day2");
    
    EXPECT_EQ(second, "1982495697");
}