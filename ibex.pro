TEMPLATE = subdirs
include(./common/build/commonconfig.pri)

CONFIG += ordered
SUBDIRS += \
    core \
    plugins\
    tests




