include(safe_mode.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = safe_mode.h

SOURCES = safe_mode.cpp

TARGET = $$qtLibraryTarget(safe_mode)

DESTDIR = ../../plugins

EXAMPLE_FILES = safe_mode.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


