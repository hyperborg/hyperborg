include(waqi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = waqi.h

SOURCES = waqi.cpp

TARGET = $$qtLibraryTarget(waqi)

DESTDIR = ../../plugins

EXAMPLE_FILES = waqi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


