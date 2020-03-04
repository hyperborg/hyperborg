include(horizon.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = horizon.h

SOURCES = horizon.cpp

TARGET = $$qtLibraryTarget(horizon)

DESTDIR = ../../plugins

EXAMPLE_FILES = horizon.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


