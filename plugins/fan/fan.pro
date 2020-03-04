include(fan.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = fan.h

SOURCES = fan.cpp

TARGET = $$qtLibraryTarget(fan)

DESTDIR = ../../plugins

EXAMPLE_FILES = fan.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


