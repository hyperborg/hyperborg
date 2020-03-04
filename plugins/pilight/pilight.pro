include(pilight.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pilight.h

SOURCES = pilight.cpp

TARGET = $$qtLibraryTarget(pilight)

DESTDIR = ../../plugins

EXAMPLE_FILES = pilight.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


