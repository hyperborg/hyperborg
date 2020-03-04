include(hassio.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = hassio.h

SOURCES = hassio.cpp

TARGET = $$qtLibraryTarget(hassio)

DESTDIR = ../../plugins

EXAMPLE_FILES = hassio.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


