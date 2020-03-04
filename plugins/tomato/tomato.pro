include(tomato.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tomato.h

SOURCES = tomato.cpp

TARGET = $$qtLibraryTarget(tomato)

DESTDIR = ../../plugins

EXAMPLE_FILES = tomato.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


