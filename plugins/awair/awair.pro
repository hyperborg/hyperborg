include(awair.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = awair.h

SOURCES = awair.cpp

TARGET = $$qtLibraryTarget(awair)

DESTDIR = ../../plugins

EXAMPLE_FILES = awair.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


