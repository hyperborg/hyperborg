include(quantum_gateway.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = quantum_gateway.h

SOURCES = quantum_gateway.cpp

TARGET = $$qtLibraryTarget(quantum_gateway)

DESTDIR = ../../plugins

EXAMPLE_FILES = quantum_gateway.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


