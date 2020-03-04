include(blackbird.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = blackbird.h

SOURCES = blackbird.cpp

TARGET = $$qtLibraryTarget(blackbird)

DESTDIR = ../../plugins

EXAMPLE_FILES = blackbird.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


