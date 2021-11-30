add_executable(tests 
    day1-test.cpp
)

target_link_libraries(tests aoc-lib gtest gtest_main gmock)