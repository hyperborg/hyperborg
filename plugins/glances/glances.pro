include(glances.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = glances.h

SOURCES = glances.cpp

TARGET = $$qtLibraryTarget(glances)

DESTDIR = ../../plugins

EXAMPLE_FILES = glances.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


