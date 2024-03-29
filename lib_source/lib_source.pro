QT -= gui

TEMPLATE = lib
DEFINES += LIB_SOURCE_LIBRARY
CONFIG -= staticlib
CONFIG += dll

CONFIG += c++11
TARGET = nfd

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    nfd_lib.cpp

HEADERS += \
    ../include/nfd.h \
    nfd_lib.h

include(../build.pri)

!contains(XCONFIG, staticscan) {
    XCONFIG += staticscan
    include(../StaticScan/staticscan.pri)
}

win32{
    LIBS += comsuppwd.lib
}
