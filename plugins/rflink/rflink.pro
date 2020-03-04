include(rflink.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rflink.h

SOURCES = rflink.cpp

TARGET = $$qtLibraryTarget(rflink)

DESTDIR = ../../plugins

EXAMPLE_FILES = rflink.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


