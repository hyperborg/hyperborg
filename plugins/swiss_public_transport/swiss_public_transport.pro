include(swiss_public_transport.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = swiss_public_transport.h

SOURCES = swiss_public_transport.cpp

TARGET = $$qtLibraryTarget(swiss_public_transport)

DESTDIR = ../../plugins

EXAMPLE_FILES = swiss_public_transport.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


