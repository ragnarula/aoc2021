#include "gtest/gtest.h"
#include "stringhelpers.h"

TEST(Tokenize, ReturnsEmptyStringForEmptyInput) {

    auto result = aoc::Tokenize("", "\n");
    ASSERT_EQ(result.size(), 0);
}

TEST(Tokenize, ReturnsArrayOfTokenizedStrings)
{
    auto result = aoc::Tokenize("Hello\nWorld", "\n");
    ASSERT_EQ(result.size(), 2);
    ASSERT_EQ(result[0], "Hello");
    ASSERT_EQ(result[1], "World");
}

TEST(Tokenize, ResutlsEmptyArrayIfInputOnlyHasOneDelimiter)
{
    auto result = aoc::Tokenize("\n", "\n");
    ASSERT_EQ(result.size(), 0);
}

TEST(HasPrefix, ReturnsTrueWhenStringHasPrefix)
{
    auto result = aoc::HasPrefix("forward 10", "forward");
    EXPECT_EQ(result, true);
}

TEST(HasPrefix, ReturnsFalseWhenStringDoesntHavePrefix)
{
    auto result = aoc::HasPrefix("down 10", "forward");
    EXPECT_EQ(result, false);
}