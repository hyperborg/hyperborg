include(ipma.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ipma.h

SOURCES = ipma.cpp

TARGET = $$qtLibraryTarget(ipma)

DESTDIR = ../../plugins

EXAMPLE_FILES = ipma.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


