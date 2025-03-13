TEMPLATE = app
QT += widgets

CONFIG += c++17
CONFIG += debug release
CONFIG += warn_on

TARGET = Inklinometry
DESTDIR = $${PWD}/bin/
INCLUDEPATH += $${PWD}/include/
    
HEADERS += \
    include/Inklin/Core/Config.h \
    include/Inklin/Core/Calculator.h \
    # include/Inklin/Gui/FileSelectorWidget.h \
    # include/Inklin/Gui/FileTypeButton.h \
    # include/Inklin/Gui/MainWindowWidget.h \
    # include/Inklin/Gui/MainWindow.h

SOURCES += \
    src/Inklin/Core/Config.cpp \
    src/Inklin/Core/Calculator.cpp \
    # src/Inklin/Gui/FileSelectorWidget.cpp \
    # src/Inklin/Gui/FileTypeButton.cpp \
    # src/Inklin/Gui/MainWindowWidget.cpp \
    # src/Inklin/Gui/MainWindow.cpp \
    src/Inklin/main.cpp
