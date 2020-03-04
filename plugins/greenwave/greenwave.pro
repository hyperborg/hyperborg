include(greenwave.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = greenwave.h

SOURCES = greenwave.cpp

TARGET = $$qtLibraryTarget(greenwave)

DESTDIR = ../../plugins

EXAMPLE_FILES = greenwave.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


