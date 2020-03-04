include(recollect_waste.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = recollect_waste.h

SOURCES = recollect_waste.cpp

TARGET = $$qtLibraryTarget(recollect_waste)

DESTDIR = ../../plugins

EXAMPLE_FILES = recollect_waste.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


