include(tradfri.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tradfri.h

SOURCES = tradfri.cpp

TARGET = $$qtLibraryTarget(tradfri)

DESTDIR = ../../plugins

EXAMPLE_FILES = tradfri.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


