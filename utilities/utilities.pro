# REM: blank space in path can make trubble for gmake
QT += core xml network

include(../utilities/src/log4qt/build.pri)
include(../utilities/src/log4qt/g++.pri)
include(../utilities/src/log4qt/log4qt.pri)


CONFIG += c++11 \
          hide_symbols

contains(DEFINES, LOG4QT_STATIC) {
    message(Building static log4qt...)
    CONFIG += staticlib
}

TEMPLATE = lib
TARGET = log4qt
QT -= gui

# .. is needed for msvc since it is treating '.' as the directory of the current file
# and not the directory where the compiled source is found
#INCLUDEPATH += .. .
INCLUDEPATH += ../utilities/src \
               ../utilities/src/log4qt

DESTDIR = ../utilities/bin/lib
INSTALL_PREFIX= ../utilities/bin
DEFINES += NOMINMAX QT_DEPRECATED_WARNINGS QT_NO_CAST_FROM_BYTEARRAY QT_USE_QSTRINGBUILDER
DEFINES += LOG4QT_LIBRARY

target.path = $$INSTALL_PREFIX/lib$$LIB_SUFFIX
INSTALLS = target

header_base.files = $$HEADERS_BASE
header_base.path = $$INSTALL_PREFIX/include/log4qt
INSTALLS += header_base
header_helpers.files = $$HEADERS_HELPERS
header_helpers.path = $$INSTALL_PREFIX/include/log4qt/helpers
INSTALLS += header_helpers
header_spi.files = $$HEADERS_SPI
header_spi.path = $$INSTALL_PREFIX/include/log4qt/spi
INSTALLS += header_spi
header_varia.files = $$HEADERS_VARIA
header_varia.path = $$INSTALL_PREFIX/include/log4qt/varia
INSTALLS += header_varia

