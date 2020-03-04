include(neurio_energy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = neurio_energy.h

SOURCES = neurio_energy.cpp

TARGET = $$qtLibraryTarget(neurio_energy)

DESTDIR = ../../plugins

EXAMPLE_FILES = neurio_energy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


