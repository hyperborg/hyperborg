include(locative.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = locative.h

SOURCES = locative.cpp

TARGET = $$qtLibraryTarget(locative)

DESTDIR = ../../plugins

EXAMPLE_FILES = locative.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


