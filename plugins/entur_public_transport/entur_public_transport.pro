include(entur_public_transport.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = entur_public_transport.h

SOURCES = entur_public_transport.cpp

TARGET = $$qtLibraryTarget(entur_public_transport)

DESTDIR = ../../plugins

EXAMPLE_FILES = entur_public_transport.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


