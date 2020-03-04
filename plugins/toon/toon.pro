include(toon.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = toon.h

SOURCES = toon.cpp

TARGET = $$qtLibraryTarget(toon)

DESTDIR = ../../plugins

EXAMPLE_FILES = toon.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


