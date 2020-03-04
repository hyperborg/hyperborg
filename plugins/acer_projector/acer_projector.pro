include(acer_projector.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = acer_projector.h

SOURCES = acer_projector.cpp

TARGET = $$qtLibraryTarget(acer_projector)

DESTDIR = ../../plugins

EXAMPLE_FILES = acer_projector.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


