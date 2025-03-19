TEMPLATE = app
QT += widgets

CONFIG += c++17
CONFIG += debug release
CONFIG += warn_on

TARGET = Inklinometry
DESTDIR = $${PWD}/../bin/
INCLUDEPATH += $${PWD}/../include/
    
HEADERS += \
    ../include/Inklin/SimpleTypes.h \
    ../include/Inklin/Core/Config.h \
    ../include/Inklin/Core/Calculator.h \
    ../include/Inklin/Gui/FileTypeButton.h \
    ../include/Inklin/Gui/TypeButtonsGroupWidget.h \
    ../include/Inklin/Gui/MainWindowWidget.h \
    ../include/Inklin/Gui/MainWindow.h

SOURCES += \
    ./src/Core/Config.cpp \
    ./src/Core/Calculator.cpp \
    ./src/Gui/FileTypeButton.cpp \
    ./src/Gui/TypeButtonsGroupWidget.cpp \
    ./src/Gui/MainWindowWidget.cpp \
    ./src/Gui/MainWindow.cpp \
    ./src/main.cpp
