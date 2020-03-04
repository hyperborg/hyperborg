include(suez_water.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = suez_water.h

SOURCES = suez_water.cpp

TARGET = $$qtLibraryTarget(suez_water)

DESTDIR = ../../plugins

EXAMPLE_FILES = suez_water.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


