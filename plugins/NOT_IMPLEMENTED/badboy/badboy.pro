include(badboy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = badboy.h

SOURCES = badboy.cpp

TARGET = $$qtLibraryTarget(badboy)

DESTDIR = ../../plugins

EXAMPLE_FILES = badboy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


