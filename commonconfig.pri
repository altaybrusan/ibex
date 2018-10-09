CONFIG += debug_and_release
DESTDIR= $$PWD/build
Release:DESTDIR = $$DESTDIR/release
Release:OBJECTS_DIR = $$DESTDIR/.obj
Release:MOC_DIR = $$DESTDIR/.moc
Release:RCC_DIR = $$DESTDIR/.rcc
Release:UI_DIR = $$DESTDIR/.ui

Debug:DESTDIR = $$DESTDIR/debug
Debug:OBJECTS_DIR = $$DESTDIR/.obj
Debug:MOC_DIR = $$DESTDIR/.moc
Debug:RCC_DIR = $$DESTDIR/.rcc
Debug:UI_DIR = $$DESTDIR/.ui

HEADERS +=

SOURCES +=

