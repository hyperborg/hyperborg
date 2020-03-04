include(tankerkoenig.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tankerkoenig.h

SOURCES = tankerkoenig.cpp

TARGET = $$qtLibraryTarget(tankerkoenig)

DESTDIR = ../../plugins

EXAMPLE_FILES = tankerkoenig.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


