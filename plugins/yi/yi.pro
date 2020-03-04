include(yi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yi.h

SOURCES = yi.cpp

TARGET = $$qtLibraryTarget(yi)

DESTDIR = ../../plugins

EXAMPLE_FILES = yi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


