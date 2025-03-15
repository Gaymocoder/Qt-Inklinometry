include(GTest.pri)

TEMPLATE = app

CONFIG -= app_bundle
CONFIG += console c++17 warn_on thread

TARGET = unit_tests
DESTDIR = $${PWD}/../build/
INCLUDEPATH += $${PWD}/../include/
    
HEADERS += \
    ../include/Inklin/SimpleTypes.h \
    ../include/Inklin/Core/Config.h \
    ../include/Inklin/Core/Calculator.h \
    # ../include/Inklin/Gui/FileSelectorWidget.h \
    # ../include/Inklin/Gui/FileTypeButton.h \
    # ../include/Inklin/Gui/MainWindowWidget.h \
    # ../include/Inklin/Gui/MainWindow.h

SOURCES += \
    ../src/Inklin/Core/Config.cpp \
    ../src/Inklin/Core/Calculator.cpp
    
HEADERS += \
    ../include/Tests/Config.h
    
SOURCES += \
    src/TestsSet/ConfigTestsSet.cpp \
    src/TestsRun/ConfigTestsRun.cpp \
    src/main.cpp
