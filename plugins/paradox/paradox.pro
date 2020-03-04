include(paradox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml serialport

INCLUDEPATH +=../../common

HEADER = paradox.h

SOURCES = paradox.cpp

TARGET = $$qtLibraryTarget(paradox)

DESTDIR = ../../plugins

EXAMPLE_FILES = paradox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


