#include "Tests/Config.h"

using getStrKeyTest = ConfigTestClass <void*, std::string, std::string, void*>;
INSTANTIATE_TEST_SUITE_P(
    ConfigTests,
    getStrKeyTest,
    ::testing::Values(
        std::make_tuple("KEY=HELLO",           "KEY", nullptr),
        std::make_tuple("KE Y= HELLO",         "KEY", nullptr),
        std::make_tuple("K EY = HEL LO",       "KEY", nullptr),
        std::make_tuple("K EY   =  HEL LO  ",  "KEY", nullptr),
        std::make_tuple("  K EY   =  HEL LO ", "K EY", nullptr)
    )
);
