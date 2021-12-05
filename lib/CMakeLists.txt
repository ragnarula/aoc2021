add_library(aoc-lib STATIC
    aoc/aoc.cpp
    day1/day1.cpp
    day2/day2.cpp
    day3/day3.cpp
    day4/day4.cpp
    day5/day5.cpp
    stringhelpers.cpp
)

target_include_directories(aoc-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})