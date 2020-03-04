include(dht.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dht.h

SOURCES = dht.cpp

TARGET = $$qtLibraryTarget(dht)

DESTDIR = ../../plugins

EXAMPLE_FILES = dht.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


