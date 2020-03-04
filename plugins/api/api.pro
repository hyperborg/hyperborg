include(api.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = api.h

SOURCES = api.cpp

TARGET = $$qtLibraryTarget(api)

DESTDIR = ../../plugins

EXAMPLE_FILES = api.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


