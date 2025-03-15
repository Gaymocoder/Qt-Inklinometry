#include "Tests/Calculator.h"

using fromAbsoluteTest = CalculatorTestClass <void*, DataSet, DataSet, DataSet>;
INSTANTIATE_TEST_SUITE_P(
    CalculatorTests,
    fromAbsoluteTest,
    ::testing::Values(
        std::make_tuple(
            DataSet { 35.92376,  20.66177,  78.15316},
            DataSet {264.52167,  32.67817, 209.83746},
            DataSet { 32.67817, 209.83746, 186.4721312178}
        )
    )
);
