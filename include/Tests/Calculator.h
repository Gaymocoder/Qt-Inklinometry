#ifndef __TESTS_CONFIG_H__
#define __TESTS_CONFIG_H__

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Inklin/Core/Calculator.h"

#include <tuple>

using namespace Inklin::Core;

template <typename TestType, typename InType1, typename InType2, typename OutType>
struct CalculatorTestClass : public ::testing::TestWithParam <std::tuple <InType1, InType2, OutType>>
{
    Calculator* testingCalculator;
    
    void SetUp()
    {
        this->testingCalculator = new Calculator("");
    }
    
    void TearDown()
    {
        delete this->testingCalculator;
    }
};

#endif
