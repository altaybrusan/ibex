# g++.pri -----------------------------------------------------------------------
*-g++* {
  NORMAL_CFLAGS = -Wno-long-long -ansi
  NORMAL_CXXFLAGS = \
    -Wnon-virtual-dtor -Wundef -Wcast-align \
    -Wchar-subscripts -Wpointer-arith \
    -Wwrite-strings -Wpacked -Wformat-security \
    -Wmissing-format-attribute -Woverloaded-virtual \
#    -Wzero-as-null-pointer-constant


  # NORMAL_CXXFLAGS += -Wconversion

  NORMAL_CFLAGS += -pedantic

  USABLE_CXXFLAGS = -Wold-style-cast
  HARD_CXXFLAGS = -Weffc++ -Wshadow
  PITA_CXXFLAGS = -Wunreachable-code

  QMAKE_CFLAGS   += $$NORMAL_CFLAGS
  QMAKE_CXXFLAGS += $$NORMAL_CFLAGS $$NORMAL_CXXFLAGS

  # Not needed - warn_on.prf adds QMAKE_CXXFLAGS_WARN_ON to QMAKE_CXXFLAGS
  #QMAKE_CFLAGS_WARN_ON   += $$NORMAL_CFLAGS
  #QMAKE_CXXFLAGS_WARN_ON += $$NORMAL_CFLAGS $$NORMAL_CXXFLAGS

  QMAKE_CXXFLAGS_WARN_ON += $$USABLE_CXXFLAGS
  #QMAKE_CXXFLAGS_WARN_ON += $$HARD_CXXFLAGS # headers must compile with this, code doesn't need to; needs patched Qt
  #QMAKE_CXXFLAGS_WARN_ON += $$PITA_CXXFLAGS # header would be nice, but it's probably pointless, due to noise from Qt and libstdc++

}

msvc {
    QMAKE_CFLAGS_WARN_ON -= -W3
    QMAKE_CFLAGS_WARN_ON += -W4

    QMAKE_CXXFLAGS_WARN_ON -= -W3
    QMAKE_CXXFLAGS_WARN_ON += -W4

    # disable common warnings in Qt/stdlib
    # disable 4127: conditional expression is constant
    #         4512: assignment operator could not be generated
    #         4267: conversion from 'size_t' to 'type', possible loss of data
    QMAKE_CXXFLAGS += -wd4127 -wd4512 -wd4267 -we4265

# /WX ... treat all warnings as errors
# /we<n> ... Treat warning <n> as error

}
#----------------------------------------------------------------------------------------
#build.pri ------------------------------------------------------------------------------
# uncomment if you want to build a static log4qt library
DEFINES += LOG4QT_STATIC
# uncomment if you want to log to a database via databaselogger
# QT += sql

LOG4QT_VERSION_MAJOR = 1
LOG4QT_VERSION_MINOR = 5
LOG4QT_VERSION_PATCH = 0

DEFINES += LOG4QT_VERSION_MAJOR=$${LOG4QT_VERSION_MAJOR}
DEFINES += LOG4QT_VERSION_MINOR=$${LOG4QT_VERSION_MINOR}
DEFINES += LOG4QT_VERSION_PATCH=$${LOG4QT_VERSION_PATCH}
DEFINES += LOG4QT_VERSION_STR='\\"$${LOG4QT_VERSION_MAJOR}.$${LOG4QT_VERSION_MINOR}.$${LOG4QT_VERSION_PATCH}\\"'
#------------------------------------------------------------------------------------------
#examples.pri -----------------------------------------------------------------------------

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

msvc {
    QMAKE_CXXFLAGS += -wd4267
}

#------------------------------------------------------------------------------------------
#basic.pro -----------------------------------------------------------------------------

INCLUDEPATH += log4qt \
               log4qt/varia


HEADERS_BASE += \
           $$PWD/appender.h \
           $$PWD/appenderskeleton.h \
           $$PWD/asyncappender.h \
           $$PWD/basicconfigurator.h \
           $$PWD/binaryfileappender.h \
           $$PWD/binarylayout.h \
           $$PWD/binarylogger.h \
           $$PWD/binaryloggingevent.h \
           $$PWD/binarylogstream.h \
           $$PWD/binarytotextlayout.h \
           $$PWD/binarywriterappender.h \
           $$PWD/colorconsoleappender.h \
           $$PWD/consoleappender.h \
           $$PWD/dailyfileappender.h \
           $$PWD/dailyrollingfileappender.h \
           $$PWD/fileappender.h \
           $$PWD/hierarchy.h \
           $$PWD/layout.h \
           $$PWD/level.h \
           $$PWD/log4qt.h \
           $$PWD/log4qtshared.h \
           $$PWD/log4qtsharedptr.h \
           $$PWD/logger.h \
           $$PWD/loggerrepository.h \
           $$PWD/loggingevent.h \
           $$PWD/logmanager.h \
           $$PWD/logstream.h \
           $$PWD/mainthreadappender.h \
           $$PWD/mdc.h \
           $$PWD/ndc.h \
           $$PWD/patternlayout.h \
           $$PWD/propertyconfigurator.h \
           $$PWD/qmllogger.h \
           $$PWD/rollingbinaryfileappender.h \
           $$PWD/rollingfileappender.h \
           $$PWD/signalappender.h \
           $$PWD/simplelayout.h \
           $$PWD/simpletimelayout.h \
           $$PWD/systemlogappender.h \
           $$PWD/ttcclayout.h \
           $$PWD/writerappender.h \
           $$PWD/xmllayout.h
HEADERS_HELPERS += \
           $$PWD/helpers/appenderattachable.h \
           $$PWD/helpers/binaryclasslogger.h \
           $$PWD/helpers/classlogger.h \
           $$PWD/helpers/configuratorhelper.h \
           $$PWD/helpers/datetime.h \
           $$PWD/helpers/dispatcher.h \
           $$PWD/helpers/factory.h \
           $$PWD/helpers/initialisationhelper.h \
           $$PWD/helpers/logerror.h \
           $$PWD/helpers/optionconverter.h \
           $$PWD/helpers/patternformatter.h \
           $$PWD/helpers/properties.h
HEADERS_SPI += \
           $$PWD/spi/filter.h
HEADERS_VARIA += \
           $$PWD/varia/binaryeventfilter.h \
           $$PWD/varia/debugappender.h \
           $$PWD/varia/denyallfilter.h \
           $$PWD/varia/levelmatchfilter.h \
           $$PWD/varia/levelrangefilter.h \
           $$PWD/varia/listappender.h \
           $$PWD/varia/nullappender.h \
           $$PWD/varia/stringmatchfilter.h
SOURCES += $$PWD/appender.cpp \
           $$PWD/appenderskeleton.cpp \
           $$PWD/basicconfigurator.cpp \
           $$PWD/colorconsoleappender.cpp \
           $$PWD/consoleappender.cpp \
           $$PWD/dailyrollingfileappender.cpp \
           $$PWD/asyncappender.cpp \
           $$PWD/dailyfileappender.cpp \
           $$PWD/mainthreadappender.cpp \
           $$PWD/fileappender.cpp \
           $$PWD/hierarchy.cpp \
           $$PWD/layout.cpp \
           $$PWD/level.cpp \
           $$PWD/logger.cpp \
           $$PWD/loggerrepository.cpp \
           $$PWD/loggingevent.cpp \
           $$PWD/logmanager.cpp \
           $$PWD/mdc.cpp \
           $$PWD/ndc.cpp \
           $$PWD/patternlayout.cpp \
           $$PWD/propertyconfigurator.cpp \
           $$PWD/rollingfileappender.cpp \
           $$PWD/signalappender.cpp \
           $$PWD/simplelayout.cpp \
           $$PWD/simpletimelayout.cpp \
           $$PWD/ttcclayout.cpp \
           $$PWD/writerappender.cpp \
           $$PWD/systemlogappender.cpp \
           $$PWD/helpers/classlogger.cpp \
           $$PWD/helpers/appenderattachable.cpp \
           $$PWD/helpers/configuratorhelper.cpp \
           $$PWD/helpers/datetime.cpp \
           $$PWD/helpers/factory.cpp \
           $$PWD/helpers/initialisationhelper.cpp \
           $$PWD/helpers/logerror.cpp \
           $$PWD/helpers/optionconverter.cpp \
           $$PWD/helpers/patternformatter.cpp \
           $$PWD/helpers/properties.cpp \
           $$PWD/helpers/dispatcher.cpp \
           $$PWD/spi/filter.cpp \
           $$PWD/varia/debugappender.cpp \
           $$PWD/varia/denyallfilter.cpp \
           $$PWD/varia/levelmatchfilter.cpp \
           $$PWD/varia/levelrangefilter.cpp \
           $$PWD/varia/listappender.cpp \
           $$PWD/varia/nullappender.cpp \
           $$PWD/varia/stringmatchfilter.cpp \
           $$PWD/logstream.cpp \
           $$PWD/binaryloggingevent.cpp \
           $$PWD/binarylogger.cpp \
           $$PWD/varia/binaryeventfilter.cpp \
           $$PWD/binarytotextlayout.cpp \
           $$PWD/binarywriterappender.cpp \
           $$PWD/binaryfileappender.cpp \
           $$PWD/binarylogstream.cpp \
           $$PWD/helpers/binaryclasslogger.cpp \
           $$PWD/rollingbinaryfileappender.cpp \
           $$PWD/binarylayout.cpp \
           $$PWD/xmllayout.cpp \
           $$PWD/qmllogger.cpp

msvc {
    QMAKE_CXXFLAGS_WARN_ON -= -w34100
    QMAKE_CXXFLAGS += -wd4100
}

# add databaseappender and -layout if QT contains sql
contains(QT, sql) {
message("Including databaseappender and -layout")
HEADERS_BASE += \
    $$PWD/databaseappender.h \
    $$PWD/databaselayout.h

SOURCES += \
    $$PWD/databaseappender.cpp \
    $$PWD/databaselayout.cpp
}

contains(QT, network) {
message("Including telnetappender")
HEADERS_BASE += \
    $$PWD/telnetappender.h

SOURCES += \
    $$PWD/telnetappender.cpp
}

win32 {
    HEADERS_BASE+=$$PWD/wdcappender.h
    SOURCES+=$$PWD/wdcappender.cpp
}
HEADERS += $$HEADERS_BASE \
           $$HEADERS_HELPERS \
           $$HEADERS_SPI \
           $$HEADERS_VARIA


!contains(QT, sql) {
message("Skipping databaseappender and -layout")
}
!contains(QT, network) {
message("Skipping telnetappender")
}
