#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Inklin/Core/Config.h"

#include <tuple>
#include <vector>

using namespace Inklin::Core;

template <typename InType1, typename InType2, typename OutType>
struct ConfigTestClass : public ::testing::TestWithParam <std::tuple <InType1, InType2, OutType>>
{
    Config* testingConfig;
    
    inline std::string getStrKey(const std::string& line) {return Config::getStrKey(line);}
    
    void SetUp()
    {
        this->testingConfig = new Config("./config.ini");
    }
    
    void TearDown()
    {
        delete this->testingConfig;
    }
};

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

INSTANTIATE_TEST_SUITE_P(
    CoreTests,
    ConfigTest,
    ::testing::Values(
        std::make_tuple("KEY=HELLO",           "KEY", nullptr),
        std::make_tuple("KE Y= HELLO",         "KEY", nullptr),
        std::make_tuple("K EY = HEL LO",       "KEY", nullptr),
        std::make_tuple("K EY   =  HEL LO  ",  "KEY", nullptr),
        std::make_tuple("  K EY   =  HEL LO ", "KEY", nullptr)
    )
);

