
#pragma once
#include "aoc/aoc.h"

#include <string>
#include <vector>
#include <array>

namespace day4
{
    using Line = std::vector<std::string>;
    using Board = std::vector<Line>;

    std::vector<Board> GetBoards(const std::vector<std::string>& input);
    std::vector<int> GetNumbers(const std::vector<std::string>& input);

    void Mark(Board& board, std::string number);
    Line GetRow(const Board& board, int row);
    Line GetCol(const Board& board, int col);
    bool IsWinner(const Board& board);
    int Score(const Board& board);

    class Solution : public aoc::ISolution
    {
    public:
        virtual std::string GetFirst(const std::vector<std::string>& input) override;
        virtual std::string GetSecond(const std::vector<std::string>& input) override;
    };
}