TEMPLATE = app
QT += widgets

CONFIG += c++17
CONFIG += debug release
CONFIG += warn_on

TARGET = Inklinometry
DESTDIR = $${PWD}/../../bin/
INCLUDEPATH += $${PWD}/../../include/
    
HEADERS += \
    ../../include/Inklin/SimpleTypes.h \
    ../../include/Inklin/Core/Config.h \
    ../../include/Inklin/Core/Calculator.h \
    #../../include/Inklin/Gui/FileSelectorWidget.h \
    #../../include/Inklin/Gui/FileTypeButton.h \
    ../../include/Inklin/Gui/MainWindowWidget.h \
    ../../include/Inklin/Gui/MainWindow.h

SOURCES += \
    Core/Config.cpp \
    Core/Calculator.cpp \
    # Gui/FileSelectorWidget.cpp \
    # Gui/FileTypeButton.cpp \
    Gui/MainWindowWidget.cpp \
    Gui/MainWindow.cpp \
    main.cpp
