#include "Tests/ConfigTest.h"

using getStrKeyTest = ConfigTestClass <void*, std::string, std::string, void*>;
INSTANTIATE_TEST_SUITE_P(
    ConfigTests,
    getStrKeyTest,
    ::testing::Values(
        std::make_tuple("KEY=HELLO",            "KEY", nullptr),
        std::make_tuple("KE Y= HELLO",          "KEY", nullptr),
        std::make_tuple("K EY = HEL LO",        "KEY", nullptr),
        std::make_tuple("K EY   =  HEL LO  ",   "KEY", nullptr),
        std::make_tuple("  K EY   =  H EL LO ", "KEY", nullptr)
    )
);

using getStrValueTest = ConfigTestClass <void**, std::string, std::string, void*>;
INSTANTIATE_TEST_SUITE_P(
    ConfigTests,
    getStrValueTest,
    ::testing::Values(
        std::make_tuple("KEY=HELLO",            "HELLO", nullptr),
        std::make_tuple("KE Y= HELLO",          "HELLO", nullptr),
        std::make_tuple("K EY = HEL LO",        "HEL LO", nullptr),
        std::make_tuple("K EY   =  HEL LO  ",   "HEL LO", nullptr),
        std::make_tuple("  K EY   =  H EL LO ", "H EL LO", nullptr)
    )
);
