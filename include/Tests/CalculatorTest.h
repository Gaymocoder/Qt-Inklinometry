#ifndef __TESTS_CALCULATOR_H__
#define __TESTS_CALCULATOR_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Inklin/Core/Calculator.h"

#include <tuple>

using namespace Inklin::Core;
const FS::path testDataDir("../tests/data/");

template <typename TestNum, typename InType1, typename InType2, typename OutType1, typename OutType2>
struct CalculatorTestClass : public ::testing::TestWithParam <std::tuple <InType1, InType2, OutType1, OutType2>>
{
    Calculator* testingCalculator;
    
    inline void calculateFile(DataSet* answers = nullptr) {testingCalculator->calculateFile(answers);}
    
    void SetUp()
    {
        this->testingCalculator = new Calculator(testDataDir/"InklinAbs.txt/0", testDataDir/"config.ini/0");
    }
    
    void TearDown()
    {
        delete this->testingCalculator;
    }
};

#endif
