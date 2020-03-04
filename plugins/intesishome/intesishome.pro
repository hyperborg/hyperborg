include(intesishome.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = intesishome.h

SOURCES = intesishome.cpp

TARGET = $$qtLibraryTarget(intesishome)

DESTDIR = ../../plugins

EXAMPLE_FILES = intesishome.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


