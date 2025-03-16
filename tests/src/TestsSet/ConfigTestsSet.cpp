#include "Tests/Config.h"

using getStrKeyTest = ConfigTestClass <void*, std::string, std::string, void*>;
TEST_P(getStrKeyTest, 0)
{
    auto [given, expected, _] = GetParam();
    EXPECT_STREQ(getStrKey(given).c_str(), expected.c_str());
}

using getStrValueTest = ConfigTestClass <void**, std::string, std::string, void*>;
TEST_P(getStrValueTest, 0)
{
    auto [given, expected, _] = GetParam();
    EXPECT_STREQ(getStrValue(given).c_str(), expected.c_str());
}
