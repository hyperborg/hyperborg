include(ted5000.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ted5000.h

SOURCES = ted5000.cpp

TARGET = $$qtLibraryTarget(ted5000)

DESTDIR = ../../plugins

EXAMPLE_FILES = ted5000.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


