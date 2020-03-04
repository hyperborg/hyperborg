include(duckdns.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = duckdns.h

SOURCES = duckdns.cpp

TARGET = $$qtLibraryTarget(duckdns)

DESTDIR = ../../plugins

EXAMPLE_FILES = duckdns.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


