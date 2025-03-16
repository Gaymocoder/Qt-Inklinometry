#include "Tests/CalculatorTest.h"

using fromAbsolute_Test = CalculatorTestClass <void*, DataSet, DataSet, DataSet, DataSet>;
TEST_P(fromAbsolute_Test, 0)
{
    auto [actPrevDataBuf, actCurrDataBuf, expPrevDataBuf, expCurrDataBuf] = GetParam();
    
    testingCalculator->fromAbsolute(&actPrevDataBuf, &actCurrDataBuf);
    
    EXPECT_EQ(actPrevDataBuf, expPrevDataBuf);
    EXPECT_EQ(actCurrDataBuf, expCurrDataBuf);
}

using fromDelta_Test = CalculatorTestClass <void**, DataSet, DataSet, DataSet, DataSet>;
TEST_P(fromDelta_Test, 0)
{
    auto [actPrevDataBuf, actCurrDataBuf, expPrevDataBuf, expCurrDataBuf] = GetParam();
    
    auto conf = testingCalculator->getConfig();
    
    testingCalculator->fromDelta(&actPrevDataBuf, &actCurrDataBuf);
    
    EXPECT_EQ(actPrevDataBuf, expPrevDataBuf);
    EXPECT_EQ(actCurrDataBuf, expCurrDataBuf);
}

using autoIdentifyFileType_Test = CalculatorTestClass <void***, FS::path, void*, Inklin::SourceDataType, void*>;
TEST_P(autoIdentifyFileType_Test, 0)
{
    auto [givenFilePath, _, expDataType, __] = GetParam();
    *testingCalculator = Calculator(givenFilePath, testDataDir/"config.ini/0");
    EXPECT_EQ(testingCalculator->getFileType(), expDataType);
}
