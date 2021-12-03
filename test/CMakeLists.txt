add_executable(tests
    aoc-test.cpp
    stringhelpers-test.cpp
    day1-test.cpp
    day2-test.cpp
    day3-test.cpp
)

target_link_libraries(tests aoc-lib gtest gtest_main gmock)