include(rmvtransport.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rmvtransport.h

SOURCES = rmvtransport.cpp

TARGET = $$qtLibraryTarget(rmvtransport)

DESTDIR = ../../plugins

EXAMPLE_FILES = rmvtransport.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


