include(serial.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = serial.h

SOURCES = serial.cpp

TARGET = $$qtLibraryTarget(serial)

DESTDIR = ../../plugins

EXAMPLE_FILES = serial.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


