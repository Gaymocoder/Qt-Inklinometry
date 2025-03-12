TEMPLATE = app
QT += widgets

CONFIG += c++17
CONFIG += debug release
CONFIG += warn_on

TARGET = Inklinometry
DESTDIR = $${PWD}/bin/
INCLUDEPATH += $${PWD}/include/
    
HEADERS += \
    include/Inklin/FileSelectorWidget.h \
    include/Inklin/FileTypeButton.h \
    include/Inklin/MainWindowWidget.h \
    include/Inklin/MainWindow.h \

SOURCES += \
    src/Inklin/FileSelectorWidget.cpp \
    src/Inklin/FileTypeButton.cpp \
    src/Inklin/MainWindowWidget.cpp \
    src/Inklin/MainWindow.cpp \
    src/main.cpp
