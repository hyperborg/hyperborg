include(uk_transport.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = uk_transport.h

SOURCES = uk_transport.cpp

TARGET = $$qtLibraryTarget(uk_transport)

DESTDIR = ../../plugins

EXAMPLE_FILES = uk_transport.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


