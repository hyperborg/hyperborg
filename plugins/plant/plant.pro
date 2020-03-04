include(plant.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = plant.h

SOURCES = plant.cpp

TARGET = $$qtLibraryTarget(plant)

DESTDIR = ../../plugins

EXAMPLE_FILES = plant.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


