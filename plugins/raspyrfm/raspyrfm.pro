include(raspyrfm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = raspyrfm.h

SOURCES = raspyrfm.cpp

TARGET = $$qtLibraryTarget(raspyrfm)

DESTDIR = ../../plugins

EXAMPLE_FILES = raspyrfm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


