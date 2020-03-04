include(sony_projector.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sony_projector.h

SOURCES = sony_projector.cpp

TARGET = $$qtLibraryTarget(sony_projector)

DESTDIR = ../../plugins

EXAMPLE_FILES = sony_projector.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


