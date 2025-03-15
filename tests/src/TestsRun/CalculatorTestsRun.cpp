#include "Tests/Calculator.h"

using SomeTest1 = CalculatorTestClass <void**, std::string, std::string, void*>;
INSTANTIATE_TEST_SUITE_P(
    CalculatorTests,
    SomeTest1,
    ::testing::Values(
        std::make_tuple("KEY",    "KEY",    nullptr),
        std::make_tuple("HELLO",  "HELLO",  nullptr),
        std::make_tuple("K EY",   "K EY",   nullptr),
        std::make_tuple("K E Y",  "K E Y",  nullptr),
        std::make_tuple("  K EY", "  K EY", nullptr)
    )
);

using SomeTest2 = CalculatorTestClass <void**, std::string, std::string, void*>;
INSTANTIATE_TEST_SUITE_P(
    CalculatorTests,
    SomeTest2,
    ::testing::Values(
        std::make_tuple("KEY",    "KEY",    nullptr),
        std::make_tuple("HELLO",  "HELLO",  nullptr),
        std::make_tuple("K EY",   "K EY",   nullptr),
        std::make_tuple("K E Y",  "K E Y",  nullptr),
        std::make_tuple("  K EY", "  K EY", nullptr)
    )
);
