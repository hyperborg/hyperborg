include(ios.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ios.h

SOURCES = ios.cpp

TARGET = $$qtLibraryTarget(ios)

DESTDIR = ../../plugins

EXAMPLE_FILES = ios.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


