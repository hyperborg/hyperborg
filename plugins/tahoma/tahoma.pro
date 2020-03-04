include(tahoma.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tahoma.h

SOURCES = tahoma.cpp

TARGET = $$qtLibraryTarget(tahoma)

DESTDIR = ../../plugins

EXAMPLE_FILES = tahoma.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


