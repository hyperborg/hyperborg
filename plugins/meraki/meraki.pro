include(meraki.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = meraki.h

SOURCES = meraki.cpp

TARGET = $$qtLibraryTarget(meraki)

DESTDIR = ../../plugins

EXAMPLE_FILES = meraki.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


