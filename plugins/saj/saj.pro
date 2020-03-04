include(saj.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = saj.h

SOURCES = saj.cpp

TARGET = $$qtLibraryTarget(saj)

DESTDIR = ../../plugins

EXAMPLE_FILES = saj.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


