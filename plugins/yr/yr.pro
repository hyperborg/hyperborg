include(yr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yr.h

SOURCES = yr.cpp

TARGET = $$qtLibraryTarget(yr)

DESTDIR = ../../plugins

EXAMPLE_FILES = yr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


