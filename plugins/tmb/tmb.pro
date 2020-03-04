include(tmb.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tmb.h

SOURCES = tmb.cpp

TARGET = $$qtLibraryTarget(tmb)

DESTDIR = ../../plugins

EXAMPLE_FILES = tmb.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


