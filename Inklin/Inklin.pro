TEMPLATE = app
QT += widgets

CONFIG += c++17 warn_on release
BUILDDIR = $$PWD/../build/Inklin/

make_builddir.target = $$BUILDDIR
make_builddir.commands = mkdir -p $$BUILDDIR
QMAKE_EXTRA_TARGETS += make_builddir
PRE_TARGETDEPS += $$BUILDDIR

TARGET = Inklinometry
DESTDIR = $${PWD}/../bin/
MOC_DIR = $${PWD}/../build/Inklin/
OBJECTS_DIR = $${PWD}/../build/Inklin/

INCLUDEPATH += $${PWD}/../include/
    
HEADERS += \
    ../include/Inklin/SimpleTypes.h \
    ../include/Inklin/Core/Config.h \
    ../include/Inklin/Core/Calculator.h \
    ../include/Inklin/Gui/FileTypeButton.h \
    # ../include/Inklin/Gui/StartPosWidget.h \
    ../include/Inklin/Gui/TypeButtonsGroupWidget.h \
    ../include/Inklin/Gui/MainWindowWidget.h \
    ../include/Inklin/Gui/MainWindow.h

SOURCES += \
    ./src/Core/Config.cpp \
    ./src/Core/Calculator.cpp \
    ./src/Gui/FileTypeButton.cpp \
    # ./src/Gui/StartPosWidget.cpp \
    ./src/Gui/TypeButtonsGroupWidget.cpp \
    ./src/Gui/MainWindowWidget.cpp \
    ./src/Gui/MainWindow.cpp \
    ./src/main.cpp
