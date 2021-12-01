#include <iostream>
#include <string>
#include "aoc/aoc.h"
#include "day1/day1.h"

int main(int argc, char *argv[])
{   
    if(argc < 2)
    {
        return 1;
    }

    aoc::Register("day1", [](){ return std::make_unique<day1::Solution>(); });

    std::string day(argv[1]);

    auto [first, second] = aoc::GetSolutionForDay(day);

    std::cout << "Part 1 [ " << first << " ]\n";
    std::cout << "Part 2 [ " << second << " ]\n";

    return 0;
}