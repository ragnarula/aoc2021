#include "day5/day5.h"
#include "stringhelpers.h"
#include <optional>
#include <algorithm>

namespace day5
{
    std::string Solution::GetFirst(const std::vector<std::string>& input) 
    {
        std::vector<Line> lines;
        std::transform(input.begin(), input.end(), std::back_inserter(lines), [](auto& elem){ return Line(elem);});

        auto [x, y] = GetDimensions(lines);

        std::vector<std::vector<int>> grid(y + 1);
        for(auto& row : grid)
        {
            row.resize(x + 1);
        }

        for(const auto& line : lines)
        {
            if(IsStraight(line)) {
                Mark(grid, line);
            }
        }

        int count = 0;
        for(int i = 0; i < x + 1; ++i)
        {
            for(int j = 0; j < y + 1; ++j)
            {
                if(grid[j][i] >= 2)
                {
                    ++count;
                }
            }
        }

        return std::to_string(count);
    }
    
    std::string Solution::GetSecond(const std::vector<std::string>& input) 
    {
        std::vector<Line> lines;
        std::transform(input.begin(), input.end(), std::back_inserter(lines), [](auto& elem){ return Line(elem);});

        auto [x, y] = GetDimensions(lines);

        std::vector<std::vector<int>> grid(y + 1);
        for(auto& row : grid)
        {
            row.resize(x + 1);
        }

        for(const auto& line : lines)
        {
            Mark(grid, line);
        }

        int count = 0;
        for(const auto& row : grid)
        {
            for(const auto& elem : row)
            {
                if(elem >= 2)
                {
                    ++count;
                }
            }
        }

        return std::to_string(count);
    }

        Line::Line(const std::string& input) 
    {
        *this = ParseLine(input);
    }

    enum ELineParse
    {
        START_X,
        START_Y,
        SEP,
        END_X,
        END_Y
    };

    Line ParseLine(const std::string& input) 
    {
        Line line;
        ELineParse state = START_X;
        int lastEnd = 0;
        for(int i = 0; i < input.size(); ++i)
        {
            if(state == START_X)
            {
                if(input[i] == ',')
                {
                    auto sub = input.substr(0, i);
                    line.points[0].x = std::stoi(sub);
                    lastEnd = i;
                    state = START_Y;
                }
            }
            else if(state == START_Y)
            {
                if(input[i] == ' ')
                {
                    auto sub = input.substr(lastEnd + 1, i - lastEnd + 1);
                    line.points[0].y = std::stoi(sub);
                    lastEnd = i;
                    state = SEP;
                }
            }
            else if(state == SEP)
            {
                if(std::isdigit(input[i]))
                {
                    lastEnd = i;
                    state = END_X;
                }
            }
            else if(state == END_X)
            {
                if(input[i] == ',')
                {
                    auto sub = input.substr(lastEnd, i - lastEnd);
                    line.points[1].x = std::stoi(sub);
                    lastEnd = i;
                    state = END_Y;
                }
            }
            else if(state == END_Y)
            {
                auto sub = input.substr(lastEnd + 1, input.size() - lastEnd + 1);
                line.points[1].y = std::stoi(sub);
                break;
            }
        }

        return line;
    }
    
    std::tuple<int, int> GetDimensions(const std::vector<Line>& lines) 
    {
        int maxX = 0;
        int maxY = 0;

        for(auto& line : lines)
        {
            maxX = std::max(maxX, line.points[0].x);
            maxX = std::max(maxX, line.points[1].x);
            maxY = std::max(maxY, line.points[0].y);
            maxY = std::max(maxY, line.points[1].y);
        }

        return {maxX, maxY};
    }

    bool IsStraight(const Line& line)
    {
        return line.points[0].x == line.points[1].x || line.points[0].y == line.points[1].y;
    }
    
    bool ContainsPoint(const Line& line, int x, int y) 
    {
        if(!IsStraight(line))
        {
            return false;
        }

        if(line.points[0].x == line.points[1].x && x == line.points[0].x)
        {
            int minY = std::min(line.points[0].y, line.points[1].y);
            int maxY = std::max(line.points[0].y, line.points[1].y);
            return y >= minY && y <= maxY;
        }
        else if(line.points[0].y == line.points[1].y && y == line.points[1].y)
        {
            int minX = std::min(line.points[0].x, line.points[1].x);
            int maxX = std::max(line.points[0].x, line.points[1].x);
            return x >= minX && x <= maxX;
        }

        return false;
    }
    
    void Mark(Grid& grid, const Line& line) 
    {
        int minY = std::min(line.points[0].y, line.points[1].y);
        int maxY = std::max(line.points[0].y, line.points[1].y);
        int minX = std::min(line.points[0].x, line.points[1].x);
        int maxX = std::max(line.points[0].x, line.points[1].x);

        if(minX == maxX)
        {
            for(int i = minY; i <= maxY; ++i)
            {
                grid[i][minX] += 1;
            }
        }
        else if(minY == maxY)
        {
            for(int i = minX; i <= maxX; ++i)
            {
                grid[minY][i] += 1;
            }
        }
        else
        {
            // x and y increasing
            // x increasing y decreasing
            // x decreasing y increasing 
            // x and y decreasing

            const int xi = std::clamp(line.points[1].x - line.points[0].x, -1, 1);
            const int yi = std::clamp(line.points[1].y - line.points[0].y, -1, 1);

            int x = line.points[0].x;
            int y = line.points[0].y;

            while(x != line.points[1].x && y != line.points[1].y)
            {
                grid[y][x] += 1;
                x += xi;
                y += yi;
            }

            grid[y][x] += 1;
        }
    }
}