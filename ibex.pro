TEMPLATE = subdirs
include(./common/build/common.pri)

CONFIG += ordered
SUBDIRS += \
    core \
    plugins\
    tests




