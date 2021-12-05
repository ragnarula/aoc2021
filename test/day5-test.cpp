#include "gtest/gtest.h"
#include "day5/day5.h"
#include "aoc/aoc.h"

TEST(Day5, Part1Example)
{
    std::vector<std::string> input = {
        "0,9 -> 5,9",
        "8,0 -> 0,8",
        "9,4 -> 3,4",
        "2,2 -> 2,1",
        "7,0 -> 7,4",
        "6,4 -> 2,0",
        "0,9 -> 2,9",
        "3,4 -> 1,4",
        "0,0 -> 8,8",
        "5,5 -> 8,2"
    };

    day5::Solution solution;
    auto result = solution.GetFirst(input);

    EXPECT_EQ(result, "5");
}

TEST(Day5, ParseLine)
{
    std::string input("0,9 -> 5,9");

    auto line = day5::ParseLine(input);
    
    EXPECT_EQ(line.points[0].x, 0);
    EXPECT_EQ(line.points[0].y, 9);
    EXPECT_EQ(line.points[1].x, 5);
    EXPECT_EQ(line.points[1].y, 9);
}

TEST(Day5, GetDimensions)
{
        std::vector<day5::Line> input = {
        {"0,9 -> 5,9"},
        {"8,0 -> 0,8"},
        {"9,4 -> 3,4"},
        {"2,2 -> 2,1"},
        {"7,0 -> 7,4"},
        {"6,4 -> 2,0"},
        {"0,9 -> 2,9"},
        {"3,4 -> 1,4"},
        {"0,0 -> 8,8"},
        {"5,5 -> 8,2"}
    };

    auto [x, y] = day5::GetDimensions(input);

    EXPECT_EQ(x, 9);
    EXPECT_EQ(y, 9);
}

TEST(Day5, IsStright)
{
    day5::Line line1("0,9 -> 5,9");
    day5::Line line2("9,4 -> 9,5");
    day5::Line line3("4,9 -> 3,5");

    EXPECT_TRUE(day5::IsStraight(line1));
    EXPECT_TRUE(day5::IsStraight(line2));
    EXPECT_FALSE(day5::IsStraight(line3));
}

TEST(Day5, ContainsPoint)
{
    day5::Line line("0,9 -> 5,9");

    EXPECT_TRUE(day5::ContainsPoint(line, 0, 9));
    EXPECT_TRUE(day5::ContainsPoint(line, 1, 9));
    EXPECT_TRUE(day5::ContainsPoint(line, 2, 9));
    EXPECT_TRUE(day5::ContainsPoint(line, 3, 9));
    EXPECT_TRUE(day5::ContainsPoint(line, 4, 9));
    EXPECT_TRUE(day5::ContainsPoint(line, 5, 9));
    EXPECT_FALSE(day5::ContainsPoint(line, 6, 9));
    EXPECT_FALSE(day5::ContainsPoint(line, 2, 3));
}

TEST(Day5, Part2Example)
{
    std::vector<std::string> input = {
        "0,9 -> 5,9",
        "8,0 -> 0,8",
        "9,4 -> 3,4",
        "2,2 -> 2,1",
        "7,0 -> 7,4",
        "6,4 -> 2,0",
        "0,9 -> 2,9",
        "3,4 -> 1,4",
        "0,0 -> 8,8",
        "5,5 -> 8,2"
    };

    day5::Solution solution;
    auto result = solution.GetSecond(input);

    EXPECT_EQ(result, "12");
}

TEST(Day5, MarkLineOnGrid)
{
    day5::Grid grid(2);
    grid[0].resize(2);
    grid[1].resize(2);

    day5::Line line1("0,0 -> 1,0");

    day5::Mark(grid, line1);

    EXPECT_EQ(grid[0][0], 1);
    EXPECT_EQ(grid[0][1], 1);

    day5::Line line2("0,0 -> 0,1");
    day5::Mark(grid, line2);
    
    EXPECT_EQ(grid[0][0], 2);
    EXPECT_EQ(grid[1][0], 1);

    day5::Line line3("0,0 -> 1,1");
    day5::Mark(grid, line3);
    
    EXPECT_EQ(grid[0][0], 3);
    EXPECT_EQ(grid[1][1], 1);
}

TEST(Day5, MarkLineOnGridBigger)
{
    day5::Grid grid(3);
    grid[0].resize(3);
    grid[1].resize(3);
    grid[2].resize(3);

    day5::Line line1("0,0 -> 2,0");

    day5::Mark(grid, line1);

    EXPECT_EQ(grid[0][0], 1);
    EXPECT_EQ(grid[0][1], 1);
    EXPECT_EQ(grid[0][2], 1);

    day5::Line line2("0,0 -> 0,2");
    day5::Mark(grid, line2);
    
    EXPECT_EQ(grid[0][0], 2);
    EXPECT_EQ(grid[1][0], 1);
    EXPECT_EQ(grid[2][0], 1);

    day5::Line line3("0,0 -> 2,2");
    day5::Mark(grid, line3);
    
    EXPECT_EQ(grid[0][0], 3);
    EXPECT_EQ(grid[1][1], 1);
    EXPECT_EQ(grid[2][2], 1);

    day5::Line line4("2,1 -> 0,1");
    day5::Mark(grid, line4);
    
    EXPECT_EQ(grid[1][2], 1);
    EXPECT_EQ(grid[1][1], 2);
    EXPECT_EQ(grid[1][0], 2);

    day5::Line line5("0,2 -> 2,0");
    day5::Mark(grid, line5);

    EXPECT_EQ(grid[2][0], 2);
    EXPECT_EQ(grid[1][1], 3);
    EXPECT_EQ(grid[0][2], 2);
}

TEST(Day5, RealInput)
{
    REGISTER(day5, day5::Solution);
    auto [first, second] = aoc::GetSolutionForDay("day5");
    EXPECT_EQ(first, "5306");
    EXPECT_EQ(second, "17787");
}