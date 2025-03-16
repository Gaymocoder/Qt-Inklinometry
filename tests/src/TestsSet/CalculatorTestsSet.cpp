#include "Tests/CalculatorTest.h"

using fromAbsoluteTest = CalculatorTestClass <void*, DataSet, DataSet, DataSet, DataSet>;
TEST_P(fromAbsoluteTest, 0)
{
    auto [actPrevDataBuf, actCurrDataBuf, expPrevDataBuf, expCurrDataBuf] = GetParam();
    
    testingCalculator->fromAbsolute(&actPrevDataBuf, &actCurrDataBuf);
    
    EXPECT_EQ(actPrevDataBuf, expPrevDataBuf);
    EXPECT_EQ(actCurrDataBuf, expCurrDataBuf);
}

using fromDeltaTest = CalculatorTestClass <void**, DataSet, DataSet, DataSet, DataSet>;
TEST_P(fromDeltaTest, 0)
{
    auto [actPrevDataBuf, actCurrDataBuf, expPrevDataBuf, expCurrDataBuf] = GetParam();
    
    auto conf = testingCalculator->getConfig();
    
    testingCalculator->fromDelta(&actPrevDataBuf, &actCurrDataBuf);
    
    EXPECT_EQ(actPrevDataBuf, expPrevDataBuf);
    EXPECT_EQ(actCurrDataBuf, expCurrDataBuf);
}
