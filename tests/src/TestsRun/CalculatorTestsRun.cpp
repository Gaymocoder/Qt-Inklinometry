#include "Tests/Calculator.h"

using fromAbsoluteTest = CalculatorTestClass <void*, DataSet, DataSet, DataSet, DataSet>;
INSTANTIATE_TEST_SUITE_P(
    CalculatorTests,
    fromAbsoluteTest,
    ::testing::Values(
        std::make_tuple(
            DataSet {0.0000000000, 559392.79000, 6137771.8200},
            DataSet {20.000000000, 559392.79000, 6137771.8200},
            DataSet {20.000000000, 559392.79000, 6137771.8200},
            DataSet {559392.79000, 6137771.8200, 20.000000000}
        ),
        std::make_tuple(
            DataSet {20.000000000, 559392.79000, 6137771.8200},
            DataSet {30.000000000, 559392.79189, 6137771.8307},
            DataSet {30.000000000, 559392.79189, 6137771.8307},
            DataSet {559392.79189, 6137771.8307, 9.9999940969}
        )
    )
);

using fromDeltaTest = CalculatorTestClass <void**, DataSet, DataSet, DataSet, DataSet>;
INSTANTIATE_TEST_SUITE_P(
    CalculatorTests,
    fromDeltaTest,
    ::testing::Values(
        std::make_tuple(
            DataSet {0.0000000000, 559392.79000, 6137771.8200},
            DataSet {20.000000000, 0.0000000000, 0.0000000000},
            DataSet {20.000000000, 559392.79000, 6137771.8200},
            DataSet {559392.79000, 6137771.8200, 20.000000000}
        ),
        std::make_tuple(
            DataSet {20.000000000, 559392.79000, 6137771.8200},
            DataSet {30.000000000, 0.0018942070, 0.0107425814},
            DataSet {30.000000000, 559392.79189, 6137771.8307},
            DataSet {559392.79189, 6137771.8307, 9.9999940504}
        )
    )
);
