#include "Tests/CalculatorTest.h"

using fromAbsolute_Test = CalculatorTestClass <void*, DataSet, DataSet, DataSet, DataSet>;
INSTANTIATE_TEST_SUITE_P(
    CalculatorTests,
    fromAbsolute_Test,
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

using fromDelta_Test = CalculatorTestClass <void**, DataSet, DataSet, DataSet, DataSet>;
INSTANTIATE_TEST_SUITE_P(
    CalculatorTests,
    fromDelta_Test,
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

using autoIdentifyFileType_Test = CalculatorTestClass <void***, FS::path, void*, Inklin::SourceDataType, void*>;
INSTANTIATE_TEST_SUITE_P(
    CalculatorTests,
    autoIdentifyFileType_Test,
    ::testing::Values(
        std::make_tuple("../tests/data/InklinAbs.txt/0.test", nullptr, Inklin::ABSOLUTE, nullptr),
        std::make_tuple("../tests/data/InklinDelta.txt/0.test", nullptr, Inklin::DELTA, nullptr),
        std::make_tuple("../tests/data/InklinAzim.txt/0.test", nullptr, Inklin::AZIMUTH, nullptr)
    )
);
