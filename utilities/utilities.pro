include($$PWD/log4qt/log4qt.pri)

# uncomment if you want to build a static log4qt library
DEFINES += LOG4QT_STATIC
# uncomment if you want to log to a database via databaselogger
# QT += sql

TEMPLATE= lib
CONFIG += staticlib
TARGET = log4qt
DESTDIR = ../utilities/log4qt

DESTDIR = ../../bin
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




