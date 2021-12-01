add_library(aoc-lib STATIC
    aoc/aoc.cpp
    day1/day1.cpp
    stringhelpers.cpp
)

target_include_directories(aoc-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})