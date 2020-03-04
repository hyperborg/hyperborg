include(itunes.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = itunes.h

SOURCES = itunes.cpp

TARGET = $$qtLibraryTarget(itunes)

DESTDIR = ../../plugins

EXAMPLE_FILES = itunes.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


