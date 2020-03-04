include(microsoft.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = microsoft.h

SOURCES = microsoft.cpp

TARGET = $$qtLibraryTarget(microsoft)

DESTDIR = ../../plugins

EXAMPLE_FILES = microsoft.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


