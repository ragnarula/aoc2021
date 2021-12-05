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
    void Register(const std::string& day, SolutionSource source)
    {
        gSources[day] = source;
    }

    std::tuple<std::string, std::string> GetSolutionForDay(const std::string& day)
    {
        if(gSources.find(day) == gSources.end())
        {
            return {};
        }

        auto source = gSources[day]();

        auto workdir = std::filesystem::current_path();
        char buffer[1024];
        std::snprintf(buffer, 1024, "%s/inputs/%s-1.txt", workdir.c_str(), day.c_str());
        std::string path1(buffer);
        std::snprintf(buffer, 1024, "%s/inputs/%s-2.txt", workdir.c_str(), day.c_str());
        std::string path2(buffer);

        auto input1 = GetLinesOfFile(path1);
        auto input2 = GetLinesOfFile(path2);

        return {source->GetFirst(input1), source->GetSecond(input2)};
    }
}