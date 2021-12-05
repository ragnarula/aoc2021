#include "gtest/gtest.h"
#include "day4/day4.h"
#include "aoc/aoc.h"

TEST(Day4, Part1Example)
{
    std::vector<std::string> input = {
        "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
        "",
        "22 13 17 11  0",
        "8  2 23  4 24",
        "21  9 14 16  7",
        "6 10  3 18  5",
        "1 12 20 15 19",
        "",
        "3 15  0  2 22",
        "9 18 13 17  5",
        "19  8  7 25 2",
        "20 11 10 24 4",
        "14 21 16 12 6",
        "",
        "14 21 17 24  4",
        "10 16 15  9 19",
        "18  8 23 26 20",
        "22 11 13  6  5",
        "2  0 12  3  7"
    };

    day4::Solution solution;
    auto result = solution.GetFirst(input);

    EXPECT_EQ(result, "4512");
}

TEST(Day4, GetBoards)
{
    std::vector<std::string> input = {
        "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
        "",
        "22 13 17 11  0",
        "8  2 23  4 24",
        "21  9 14 16  7",
        "6 10  3 18  5",
        "1 12 20 15 19",
        "",
        "3 15  0  2 22",
        "9 18 13 17  5",
        "19  8  7 25 2",
        "20 11 10 24 4",
        "14 21 16 12 6",
        "",
        "14 21 17 24  4",
        "10 16 15  9 19",
        "18  8 23 26 20",
        "22 11 13  6  5",
        "2  0 12  3  7"
    };

    auto result = day4::GetBoards(input);
    EXPECT_EQ(result.size(), 3);

    for(const auto& board : result)
    {
        EXPECT_EQ(board.size(), 5);
        for(const auto& row : board)
        {
            EXPECT_EQ(row.size(), 5);
            for(const auto& item : row)
            {
                EXPECT_EQ(item.size() > 0, true);
                for(const auto& digit : item)
                {
                    EXPECT_EQ(std::isdigit(digit), true);
                }
            }
        }
    }
}

TEST(Day4, Mark)
{
    day4::Board board = {
        {"22", "13", "17", "11", "0"},
        {"8", "2", "23", "4", "24"},
        {"21", "9", "14", "16", "7"},
        {"6", "10", "3", "18", "5"},
        {"1", "12", "20", "15", "19"}
    };

    day4::Mark(board, "11");

    EXPECT_EQ(board[0][3], "X");
}

TEST(Day4, GetRow)
{
    day4::Board board = {
        {"22", "13", "17", "11", "0"},
        {"8", "2", "23", "4", "24"},
        {"21", "9", "14", "16", "7"},
        {"6", "10", "3", "18", "5"},
        {"1", "12", "20", "15", "19"}
    };

    auto row = day4::GetRow(board, 2);

    EXPECT_EQ(row, board[2]);
}

TEST(Day4, GetCol)
{
    day4::Board board = {
        {"22", "13", "17", "11", "0"},
        {"8", "2", "23", "4", "24"},
        {"21", "9", "14", "16", "7"},
        {"6", "10", "3", "18", "5"},
        {"1", "12", "20", "15", "19"}
    };

    auto col = day4::GetCol(board, 2);

    EXPECT_EQ(col, (day4::Line{"17", "23", "14", "3", "20"}));
}

TEST(Day4, IsWinnerRow)
{
    day4::Board board = {
        {"X", "X", "X", "X", "X"},
        {"8", "2", "23", "4", "24"},
        {"21", "9", "14", "16", "7"},
        {"6", "10", "3", "18", "5"},
        {"1", "12", "20", "15", "19"}
    };

    auto result = day4::IsWinner(board);

    EXPECT_EQ(result, true);
}

TEST(Day4, IsWinnerCol)
{
    day4::Board board = {
        {"22", "13", "X", "11", "0"},
        {"8", "2", "X", "4", "24"},
        {"21", "9", "X", "16", "7"},
        {"6", "10", "X", "18", "5"},
        {"1", "12", "X", "15", "19"}
    };

    auto result = day4::IsWinner(board);

    EXPECT_EQ(result, true);
}


TEST(Day4, IsWinnerNone)
{
    day4::Board board = {
        {"22", "13", "17", "11", "0"},
        {"8", "2", "23", "4", "24"},
        {"21", "9", "14", "16", "7"},
        {"6", "10", "3", "18", "5"},
        {"1", "12", "20", "15", "19"}
    };

    auto result = day4::IsWinner(board);

    EXPECT_EQ(result, false);
}


TEST(Day4, Score)
{
    day4::Board board = {
        {"X", "X", "X", "X", "X"},
        {"10", "16", "15", "X", "19"},
        {"18", "8", "X", "26", "20"},
        {"22", "X", "13", "6", "X"},
        {"X", "X","12 ", "3 ", "X"}   
    };

    auto result = day4::Score(board);

    EXPECT_EQ(result, 188);
}

TEST(Day4, Part1)
{
    REGISTER(day4, day4::Solution);
    auto [first, second] = aoc::GetSolutionForDay("day4");
    
    EXPECT_EQ(first, "23177");
}

TEST(Day4, Part2Example)
{
    std::vector<std::string> input = {
        "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
        "",
        "22 13 17 11  0",
        "8  2 23  4 24",
        "21  9 14 16  7",
        "6 10  3 18  5",
        "1 12 20 15 19",
        "",
        "3 15  0  2 22",
        "9 18 13 17  5",
        "19  8  7 25 2",
        "20 11 10 24 4",
        "14 21 16 12 6",
        "",
        "14 21 17 24  4",
        "10 16 15  9 19",
        "18  8 23 26 20",
        "22 11 13  6  5",
        "2  0 12  3  7"
    };

    day4::Solution solution;
    auto result = solution.GetSecond(input);

    EXPECT_EQ(result, "1924");
}

TEST(Day4, Part2)
{
    REGISTER(day4, day4::Solution);
    auto [first, second] = aoc::GetSolutionForDay("day4");
    
    EXPECT_EQ(second, "6804");
}