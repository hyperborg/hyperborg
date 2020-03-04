include(simulated.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = simulated.h

SOURCES = simulated.cpp

TARGET = $$qtLibraryTarget(simulated)

DESTDIR = ../../plugins

EXAMPLE_FILES = simulated.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


