include(solaredge.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = solaredge.h

SOURCES = solaredge.cpp

TARGET = $$qtLibraryTarget(solaredge)

DESTDIR = ../../plugins

EXAMPLE_FILES = solaredge.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


