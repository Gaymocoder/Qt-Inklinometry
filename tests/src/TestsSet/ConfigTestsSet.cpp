#include "Tests/Config.h"

typedef std::tuple <std::string, std::string, void*> TestSet;
using ConfigTest = ConfigTestClass <std::string, std::string, void*>;
TEST_P(ConfigTest, getStrKey)
{
    TestSet test_data = GetParam();
    
    std::string& given = std::get <0> (test_data);
    std::string& expected = std::get <1> (test_data);
    std::string result = getStrKey(given);
    
    EXPECT_STREQ(result.c_str(), expected.c_str());
}
