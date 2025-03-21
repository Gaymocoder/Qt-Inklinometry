include(GTest.pri)

TEMPLATE = app

CONFIG -= app_bundle
CONFIG += console c++17 warn_on thread
INCLUDEPATH += $${PWD}/../include/
BUILDDIR = $$PWD/../build/Tests/

make_builddir.target = $$BUILDDIR
make_builddir.commands = mkdir -p $$BUILDDIR
QMAKE_EXTRA_TARGETS += make_builddir
PRE_TARGETDEPS += $$BUILDDIR

TARGET = unit_tests
MOC_DIR = $$BUILDDIR/
OBJECTS_DIR = $$BUILDDIR/
DESTDIR = $$BUILDDIR/../
    
HEADERS += \
    ../include/Inklin/SimpleTypes.h \
    ../include/Inklin/Core/Config.h \
    ../include/Inklin/Core/Calculator.h \

SOURCES += \
    ../Inklin/src/Core/Config.cpp \
    ../Inklin/src/Core/Calculator.cpp
    
HEADERS += \
    ../include/Tests/ConfigTest.h \
    ../include/Tests/CalculatorTest.h
    
SOURCES += \
    ./src/TestsSet/ConfigTestsSet.cpp \
    ./src/TestsRun/ConfigTestsRun.cpp \
    ./src/TestsSet/CalculatorTestsSet.cpp \
    ./src/TestsRun/CalculatorTestsRun.cpp \
    ./src/main.cpp
