include(unifiled.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = unifiled.h

SOURCES = unifiled.cpp

TARGET = $$qtLibraryTarget(unifiled)

DESTDIR = ../../plugins

EXAMPLE_FILES = unifiled.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


