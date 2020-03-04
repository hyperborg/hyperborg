include(season.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = season.h

SOURCES = season.cpp

TARGET = $$qtLibraryTarget(season)

DESTDIR = ../../plugins

EXAMPLE_FILES = season.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


