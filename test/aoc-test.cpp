#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "aoc/aoc.h"

TEST(Aoc, GetsEmptyStringsWhenNoSolutionExists)
{
    auto [first, second] = aoc::GetSolutionForDay("day777");
    ASSERT_EQ(first, "");
    ASSERT_EQ(second, "");
}

class MockSolution : public aoc::ISolution
{
public:
    MOCK_METHOD(std::string, GetFirst, (const std::vector<std::string>&), (override));
    MOCK_METHOD(std::string, GetSecond, (const std::vector<std::string>&), (override));
};

TEST(Aoc, GetsSolutionsFromRegisteredSolutionForDay)
{
    aoc::Register("day1", [this](){ 
        auto source = std::make_unique<MockSolution>();
        using testing::Return;
        EXPECT_CALL(*source.get(), GetFirst).WillRepeatedly(Return("first"));
        EXPECT_CALL(*source.get(), GetSecond).WillRepeatedly(Return("second"));
        return source;
    });

    auto [firstRes, secondRes] = aoc::GetSolutionForDay("day1");
    ASSERT_EQ(firstRes, "first");
    ASSERT_EQ(secondRes, "second");
}