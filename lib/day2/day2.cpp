#include "day2/day2.h"
#include "stringhelpers.h"

namespace day2
{
    int GetUnits(const std::string& command) 
    {
        auto pos = command.find(' ');
        if(pos != std::string::npos)
        {
            return std::stoi(command.substr(pos + 1, command.size()));
        }
        return 0;
    }

    std::string Solution::GetFirst(const std::vector<std::string>& input) 
    {
        static const std::string forward("forward");
        static const std::string up("up");
        static const std::string down("down");

        int forwardPos = 0;
        int depth = 0;

        for(const auto& line : input)
        {
            const auto units = GetUnits(line);;
            if(aoc::HasPrefix(line, forward))
            {
                forwardPos += units;
            }
            else if(aoc::HasPrefix(line, up))
            {
                depth -= units;
            }
            else if(aoc::HasPrefix(line, down))
            {
                depth += units;
            }
        }

        return std::to_string(forwardPos * depth);
    }
    
    std::string Solution::GetSecond(const std::vector<std::string>& input) 
    {
        static const std::string forward("forward");
        static const std::string up("up");
        static const std::string down("down");

        int forwardPos = 0;
        int depth = 0;
        int aim = 0;

        for(const auto& line : input)
        {
            const auto units = GetUnits(line);
            if(aoc::HasPrefix(line, forward))
            {
                forwardPos += units;
                depth += aim * units;
            }
            else if(aoc::HasPrefix(line, up))
            {
                aim -= units;
            }
            else if(aoc::HasPrefix(line, down))
            {
                aim += units;
            }
        }

        return std::to_string(forwardPos * depth);
    }
}