include(roomba.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = roomba.h

SOURCES = roomba.cpp

TARGET = $$qtLibraryTarget(roomba)

DESTDIR = ../../plugins

EXAMPLE_FILES = roomba.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


