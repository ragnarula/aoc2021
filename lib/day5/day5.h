
#pragma once
#include "aoc/aoc.h"

#include <string>
#include <vector>

namespace day5
{
    struct Point
    {
        int x, y = 0;
    };

    struct Line
    {
        Point points[2];
        Line(const std::string& input);
        Line() {}
    };

    Line ParseLine(const std::string& input);
    bool IsStraight(const Line& line);
    bool ContainsPoint(const Line& line, int x, int y);

    using Grid = std::vector<std::vector<int>>;
    void Mark(Grid& grid, const Line& line);
    
    std::tuple<int, int> GetDimensions(const std::vector<Line>& lines);

    class Solution : public aoc::ISolution
    {
    public:
        virtual std::string GetFirst(const std::vector<std::string>& input) override;
        virtual std::string GetSecond(const std::vector<std::string>& input) override;
    };
}