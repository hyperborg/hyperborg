include(lightwave.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lightwave.h

SOURCES = lightwave.cpp

TARGET = $$qtLibraryTarget(lightwave)

DESTDIR = ../../plugins

EXAMPLE_FILES = lightwave.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


