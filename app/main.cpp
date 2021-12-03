#include <iostream>
#include <string>
#include "aoc/aoc.h"
#include "day1/day1.h"
#include "day2/day2.h"
#include "day3/day3.h"

int main(int argc, char *argv[])
{   
    if(argc < 2)
    {
        return 1;
    }

    REGISTER(day1, day1::Solution);
    REGISTER(day2, day2::Solution);
    REGISTER(day3, day3::Solution);

    std::string day(argv[1]);

    auto [first, second] = aoc::GetSolutionForDay(day);

    std::cout << "Part 1 [ " << first << " ]\n";
    std::cout << "Part 2 [ " << second << " ]\n";

    return 0;
}