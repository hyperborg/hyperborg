include(growatt_server.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = growatt_server.h

SOURCES = growatt_server.cpp

TARGET = $$qtLibraryTarget(growatt_server)

DESTDIR = ../../plugins

EXAMPLE_FILES = growatt_server.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


