#include "Tests/Calculator.h"

using fromAbsoluteTest = CalculatorTestClass <void*, DataSet, DataSet, DataSet>;
TEST_P(fromAbsoluteTest, 0)
{
    auto [actPrevDataBuf, actCurrDataBuf, expCurrDataBuf] = GetParam();
    auto expPrevDataBuf = actCurrDataBuf;
    
    Calculator::fromAbsolute(&actPrevDataBuf, &actCurrDataBuf);
    
    EXPECT_EQ(actPrevDataBuf.Value1, expPrevDataBuf.Value1);
    EXPECT_EQ(actPrevDataBuf.Value2, expPrevDataBuf.Value2);
    EXPECT_EQ(actPrevDataBuf.Value3, expPrevDataBuf.Value3);
    
    EXPECT_EQ(actCurrDataBuf.Value1, expCurrDataBuf.Value1);
    EXPECT_EQ(actCurrDataBuf.Value2, expCurrDataBuf.Value2);
    EXPECT_EQ(actCurrDataBuf.Value3, expCurrDataBuf.Value3);
}

