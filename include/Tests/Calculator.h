#ifndef __TESTS_CALCULATOR_H__
#define __TESTS_CALCULATOR_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Inklin/Core/Calculator.h"

#include <tuple>

using namespace Inklin::Core;

template <typename TestNum, typename InType1, typename InType2, typename OutType1, typename OutType2>
struct CalculatorTestClass : public ::testing::TestWithParam <std::tuple <InType1, InType2, OutType1, OutType2>>
{
    Calculator* testingCalculator;
    
    void SetUp()
    {
        this->testingCalculator = new Calculator("Inklin_delta.txt", "../tests/data/Config.ini");
    }
    
    void TearDown()
    {
        delete this->testingCalculator;
    }
};

#endif
