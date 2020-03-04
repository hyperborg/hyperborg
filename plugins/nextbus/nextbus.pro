include(nextbus.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nextbus.h

SOURCES = nextbus.cpp

TARGET = $$qtLibraryTarget(nextbus)

DESTDIR = ../../plugins

EXAMPLE_FILES = nextbus.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


