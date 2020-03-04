include(upc_connect.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = upc_connect.h

SOURCES = upc_connect.cpp

TARGET = $$qtLibraryTarget(upc_connect)

DESTDIR = ../../plugins

EXAMPLE_FILES = upc_connect.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


