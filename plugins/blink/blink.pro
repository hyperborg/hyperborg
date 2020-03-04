include(blink.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = blink.h

SOURCES = blink.cpp

TARGET = $$qtLibraryTarget(blink)

DESTDIR = ../../plugins

EXAMPLE_FILES = blink.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


