add_library(aoc-lib STATIC
    day1/day1.cpp
)

target_include_directories(aoc-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})