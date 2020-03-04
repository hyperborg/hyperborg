include(monoprice.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = monoprice.h

SOURCES = monoprice.cpp

TARGET = $$qtLibraryTarget(monoprice)

DESTDIR = ../../plugins

EXAMPLE_FILES = monoprice.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


