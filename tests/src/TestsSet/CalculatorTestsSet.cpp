#include "Tests/CalculatorTest.h"

#include <fstream>

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
    ASSERT_EQ(testingCalculator->getFileType(), expDataType);
}

using calculateAbsFile_Test = CalculatorTestClass <void****, int, void*, void*, void*>;
TEST_P(calculateAbsFile_Test,  0)
{
    auto [testIndex, _, __, ___] = GetParam();
    
    FS::path absTestsDir(testDataDir/"InklinAbs.txt");
    FS::path testData {absTestsDir/(std::to_string(testIndex) + ".test")};
    FS::path answData {absTestsDir/(std::to_string(testIndex) + ".answ")};
    
    std::cout << testData << std::endl;
    
    std::string strbuf;
    DataSet answers[20];
    std::ifstream answersFile(answData.string());
    for(int i = 0; i < 20; ++i)
    {
        std::getline(answersFile, strbuf);
        std::stringstream ssbuf(strbuf);
        ssbuf >> answers[i];
    }
    
    *testingCalculator = Calculator(testData, testDataDir/"config.ini/0");
    calculateFile(answers);
    
    for(int i = 0; i < 20; ++i)
        ASSERT_NE(answers[i], (DataSet{-1, -1, -1}));
}

using calculateDeltaFile_Test = CalculatorTestClass <void*****, int, void*, void*, void*>;
TEST_P(calculateDeltaFile_Test,  0)
{
    auto [testIndex, _, __, ___] = GetParam();
    
    FS::path absTestsDir(testDataDir/"InklinDelta.txt");
    FS::path testData {absTestsDir/(std::to_string(testIndex) + ".test")};
    FS::path answData {absTestsDir/(std::to_string(testIndex) + ".answ")};
    
    std::string strbuf;
    DataSet answers[20];
    std::ifstream answersFile(answData.string());
    for(int i = 0; i < 20; ++i)
    {
        std::getline(answersFile, strbuf);
        std::stringstream ssbuf(strbuf);
        ssbuf >> answers[i];
    }
    
    *testingCalculator = Calculator(testData, testDataDir/"config.ini/0");
    calculateFile(answers);
    
    for(int i = 0; i < 20; ++i)
        ASSERT_NE(answers[i], (DataSet{-1, -1, -1}));
}

using calculateAzimFile_Test = CalculatorTestClass <void******, int, void*, void*, void*>;
TEST_P(calculateAzimFile_Test,  0)
{
    auto [testIndex, _, __, ___] = GetParam();
    
    FS::path absTestsDir(testDataDir/"InklinAzim.txt");
    FS::path testData {absTestsDir/(std::to_string(testIndex) + ".test")};
    FS::path answData {absTestsDir/(std::to_string(testIndex) + ".answ")};
    
    std::string strbuf;
    DataSet answers[20];
    std::ifstream answersFile(answData.string());
    for(int i = 0; i < 20; ++i)
    {
        std::getline(answersFile, strbuf);
        std::stringstream ssbuf(strbuf);
        ssbuf >> answers[i];
    }
    
    *testingCalculator = Calculator(testData, testDataDir/"config.ini/0");
    calculateFile(answers);
    
    for(int i = 0; i < 20; ++i)
        ASSERT_NE(answers[i], (DataSet{-1, -1, -1}));
}
