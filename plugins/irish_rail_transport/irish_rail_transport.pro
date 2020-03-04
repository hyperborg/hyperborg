include(irish_rail_transport.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = irish_rail_transport.h

SOURCES = irish_rail_transport.cpp

TARGET = $$qtLibraryTarget(irish_rail_transport)

DESTDIR = ../../plugins

EXAMPLE_FILES = irish_rail_transport.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


