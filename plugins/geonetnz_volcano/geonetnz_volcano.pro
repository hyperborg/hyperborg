include(geonetnz_volcano.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = geonetnz_volcano.h

SOURCES = geonetnz_volcano.cpp

TARGET = $$qtLibraryTarget(geonetnz_volcano)

DESTDIR = ../../plugins

EXAMPLE_FILES = geonetnz_volcano.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


