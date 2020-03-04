include(nx584.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nx584.h

SOURCES = nx584.cpp

TARGET = $$qtLibraryTarget(nx584)

DESTDIR = ../../plugins

EXAMPLE_FILES = nx584.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


