include(onkyo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = onkyo.h

SOURCES = onkyo.cpp

TARGET = $$qtLibraryTarget(onkyo)

DESTDIR = ../../plugins

EXAMPLE_FILES = onkyo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


