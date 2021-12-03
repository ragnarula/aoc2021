#include <vector>
#include <string>

#include "gtest/gtest.h"
#include "day3/day3.h"
#include "aoc/aoc.h"

TEST(Day3, Part1Example)
{
    std::vector<std::string> input = {
        "00100",
        "11110",
        "10110",
        "10111",
        "10101",
        "01111",
        "00111",
        "11100",
        "10000",
        "11001",
        "00010",
        "01010"
    };

    day3::Solution solution;
    auto result = solution.GetFirst(input);
    EXPECT_EQ(result, "198");
}

TEST(Day3, Part1)
{
    REGISTER(day3, day3::Solution);
    auto [first, second] = aoc::GetSolutionForDay("day3");
    
    EXPECT_EQ(first, "2498354");
}

TEST(Day3, GetMajorities)
{
    std::vector<std::bitset<5>> input = {
        std::bitset<5>("00100"),
        std::bitset<5>("11110"),
        std::bitset<5>("10110"),
        std::bitset<5>("10111"),
        std::bitset<5>("10101"),
        std::bitset<5>("01111"),
        std::bitset<5>("00111"),
        std::bitset<5>("11100"),
        std::bitset<5>("10000"),
        std::bitset<5>("11001"),
        std::bitset<5>("00010"),
        std::bitset<5>("01010")
    };

    std::bitset<5> result = day3::GetMajorities(input);

    EXPECT_EQ(result, std::bitset<5>("10110"));
}

TEST(Day3, GetMajoritiesEqual)
{
    std::vector<std::bitset<1>> input = {
        std::bitset<1>("1"),
        std::bitset<1>("0")
    };

    std::bitset<1> result = day3::GetMajorities(input, true);
    EXPECT_EQ(result, std::bitset<1>("1"));

    result = day3::GetMajorities(input, false);
    EXPECT_EQ(result, std::bitset<1>("0"));
}

TEST(Day3, Part2Example)
{
    std::vector<std::string> input = {
        "00100",
        "11110",
        "10110",
        "10111",
        "10101",
        "01111",
        "00111",
        "11100",
        "10000",
        "11001",
        "00010",
        "01010"
    };

    day3::Solution solution;
    auto result = solution.GetSecond(input);
    EXPECT_EQ(result, "230");
}

TEST(Day3, FilterForCriteria)
{
    std::vector<std::bitset<5>> input = {
        std::bitset<5>("00100"),
        std::bitset<5>("11110"),
        std::bitset<5>("10110"),
        std::bitset<5>("10111"),
        std::bitset<5>("10101"),
        std::bitset<5>("01111"),
        std::bitset<5>("00111"),
        std::bitset<5>("11100"),
        std::bitset<5>("10000"),
        std::bitset<5>("11001"),
        std::bitset<5>("00010"),
        std::bitset<5>("01010")
    };

    const auto mostCommonResult = day3::FilterByCriteria(input, 5, day3::MostCommon);
    EXPECT_EQ(mostCommonResult, std::bitset<5>("10111"));

    const auto leastCommonResult = day3::FilterByCriteria(input, 5, day3::LeastCommon);
    EXPECT_EQ(leastCommonResult, std::bitset<5>("01010"));
}

TEST(Day3, Part2)
{
    REGISTER(day3, day3::Solution);
    auto [first, second] = aoc::GetSolutionForDay("day3");
    
    EXPECT_EQ(second, "3277956");
}