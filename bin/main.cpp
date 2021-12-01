#include <iostream>
#include <fstream>
#include <filesystem>
#include "solution.h"
#include "stringhelpers.h"

std::vector<std::string> GetLinesOfFile(std::string path)
{
    std::ifstream file(path);
    std::string input;
    if(file.is_open())
    {
        std::getline(file, input, '\0');
    }

    return aoc::Tokenize(input, "\n");
}

int main(int argc, char *argv[])
{
    if(argc < 1)
    {
        return 1;
    }

    auto currentPath = aoc::Tokenize(argv[0], "/");
    if (currentPath.size() == 0)
    {
        return 1;
    }

    auto binaryName = currentPath[currentPath.size() - 1];

    auto workdir = std::filesystem::current_path();
    char buffer[1024];
    std::snprintf(buffer, 1024, "%s/%s-1.txt", workdir.c_str(), binaryName.c_str());
    std::string path1(buffer);
    std::snprintf(buffer, 1024, "%s/%s-2.txt", workdir.c_str(), binaryName.c_str());
    std::string path2(buffer);

    auto solution1 = solution::first(GetLinesOfFile(path1));
    auto solution2 = solution::second(GetLinesOfFile(path2));

    std::cout << "Part 1 [ " << solution1 << " ]\n";
    std::cout << "Part 2 [ " << solution2 << " ]\n";
    return 0;
}