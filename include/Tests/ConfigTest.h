#ifndef __TESTS_CONFIG_H__
#define __TESTS_CONFIG_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Inklin/Core/Calculator.h"

#include <tuple>

using namespace Inklin::Core;

template <typename TestNum, typename InType1, typename InType2, typename OutType>
struct ConfigTestClass : public ::testing::TestWithParam <std::tuple <InType1, InType2, OutType>>
{
    Config* testingConfig;
    
    inline std::string getStrKey(const std::string& line) {return Config::getStrKey(line);}
    inline std::string getStrValue(const std::string& line) {return Config::getStrValue(line);}
    
    void SetUp()
    {
        this->testingConfig = new Config("./config.ini");
    }
    
    void TearDown()
    {
        delete this->testingConfig;
    }
};

#endif
