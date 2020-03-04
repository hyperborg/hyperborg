include(automatic.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = automatic.h

SOURCES = automatic.cpp

TARGET = $$qtLibraryTarget(automatic)

DESTDIR = ../../plugins

EXAMPLE_FILES = automatic.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


