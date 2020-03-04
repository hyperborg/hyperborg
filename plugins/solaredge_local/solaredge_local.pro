include(solaredge_local.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = solaredge_local.h

SOURCES = solaredge_local.cpp

TARGET = $$qtLibraryTarget(solaredge_local)

DESTDIR = ../../plugins

EXAMPLE_FILES = solaredge_local.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


