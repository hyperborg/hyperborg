include(incomfort.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = incomfort.h

SOURCES = incomfort.cpp

TARGET = $$qtLibraryTarget(incomfort)

DESTDIR = ../../plugins

EXAMPLE_FILES = incomfort.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


