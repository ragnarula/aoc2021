#include "aoc/aoc.h"
#include "stringhelpers.h"
#include <map>
#include <filesystem>
#include <fstream>

namespace
{
    std::map<std::string, aoc::SolutionSource> gSources;


    std::vector<std::string> GetLinesOfFile(std::string path)
    {
        std::ifstream file(path);
        std::vector<std::string> lines;
        std::string input;
        if(file.is_open())
        {
            while(std::getline(file, input))
            {
                lines.push_back(std::move(input));
            }
        }

        return lines;
    }
}

namespace aoc
{
    std::unique_ptr<ISolution> GetSolution(const std::string& day) 
    {
        if(gSources.find(day) != gSources.end())
        {
            return gSources[day]();
        }
        return {};
    }
    
    std::vector<std::string> GetInputForDay(const std::string& day, EPart part) 
    {
        static const auto workdir = std::filesystem::current_path();
        static const size_t bufsize = 1024;
        char buffer[bufsize];

        std::snprintf(buffer, bufsize, "%s/inputs/%s.txt", workdir.c_str(), day.c_str()); 
        std::string path(buffer);
        auto input = GetLinesOfFile(path);

        if(input.empty())
        {
            if(part == EPart::First)
            {
                std::snprintf(buffer, bufsize, "%s/inputs/%s-1.txt", workdir.c_str(), day.c_str()); 
                std::string path1(buffer);
                return GetLinesOfFile(path1);
            }
            else
            {
                std::string path1(buffer);
                std::snprintf(buffer, bufsize, "%s/inputs/%s-2.txt", workdir.c_str(), day.c_str());
                std::string path2(buffer);
                return GetLinesOfFile(path2);
            }
        }

        return input;
    }

    void Register(const std::string& day, SolutionSource source)
    {
        gSources[day] = source;
    }

    std::tuple<std::string, std::string> GetSolutionForDay(const std::string& day)
    {
        auto solution = GetSolution(day);
        if(!solution)
        {
            return {};
        }
        const auto input1 = GetInputForDay(day, EPart::First);
        const auto input2 = GetInputForDay(day, EPart::Second);
        
        const auto sol1 = input1.empty() ? "" : solution->GetFirst(input1);
        const auto sol2 = input2.empty() ? "" : solution->GetSecond(input2);

        return {sol1, sol2};
    }
}