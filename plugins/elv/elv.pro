include(elv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = elv.h

SOURCES = elv.cpp

TARGET = $$qtLibraryTarget(elv)

DESTDIR = ../../plugins

EXAMPLE_FILES = elv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


