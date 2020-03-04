include(tof.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tof.h

SOURCES = tof.cpp

TARGET = $$qtLibraryTarget(tof)

DESTDIR = ../../plugins

EXAMPLE_FILES = tof.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


