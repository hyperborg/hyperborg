include(tcp.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tcp.h

SOURCES = tcp.cpp

TARGET = $$qtLibraryTarget(tcp)

DESTDIR = ../../plugins

EXAMPLE_FILES = tcp.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


