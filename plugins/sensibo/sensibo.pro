include(sensibo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sensibo.h

SOURCES = sensibo.cpp

TARGET = $$qtLibraryTarget(sensibo)

DESTDIR = ../../plugins

EXAMPLE_FILES = sensibo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


