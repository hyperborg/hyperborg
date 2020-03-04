include(blinkt.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = blinkt.h

SOURCES = blinkt.cpp

TARGET = $$qtLibraryTarget(blinkt)

DESTDIR = ../../plugins

EXAMPLE_FILES = blinkt.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


