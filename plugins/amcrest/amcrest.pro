include(amcrest.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = amcrest.h

SOURCES = amcrest.cpp

TARGET = $$qtLibraryTarget(amcrest)

DESTDIR = ../../plugins

EXAMPLE_FILES = amcrest.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


