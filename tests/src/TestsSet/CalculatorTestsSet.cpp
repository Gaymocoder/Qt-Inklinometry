#include "Tests/Calculator.h"

using SomeTest1 = CalculatorTestClass <void*, std::string, std::string, void*>;
TEST_P(SomeTest1, 0)
{
    auto [given, expected, _] = GetParam();
    EXPECT_STREQ(given.c_str(), expected.c_str());
}

using SomeTest2 = CalculatorTestClass <void**, std::string, std::string, void*>;
TEST_P(SomeTest2, 0)
{
    auto [given, expected, _] = GetParam();
    EXPECT_STREQ(given.c_str(), expected.c_str());
}
