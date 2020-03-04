include(moon.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = moon.h

SOURCES = moon.cpp

TARGET = $$qtLibraryTarget(moon)

DESTDIR = ../../plugins

EXAMPLE_FILES = moon.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


