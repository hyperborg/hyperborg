include(lg_netcast.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lg_netcast.h

SOURCES = lg_netcast.cpp

TARGET = $$qtLibraryTarget(lg_netcast)

DESTDIR = ../../plugins

EXAMPLE_FILES = lg_netcast.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


