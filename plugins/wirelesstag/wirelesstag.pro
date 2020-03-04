include(wirelesstag.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = wirelesstag.h

SOURCES = wirelesstag.cpp

TARGET = $$qtLibraryTarget(wirelesstag)

DESTDIR = ../../plugins

EXAMPLE_FILES = wirelesstag.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


