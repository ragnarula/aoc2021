#include "gtest/gtest.h"
#include "day1/day1.h"

TEST(Day1, CountsIncreases) {
    std::vector<int> input { 1, 2, 3, 1, 5, 4, 7};

    ASSERT_EQ(day1::CountIncreases(input), 4);
}