include(androidtv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = androidtv.h

SOURCES = androidtv.cpp

TARGET = $$qtLibraryTarget(androidtv)

DESTDIR = ../../plugins

EXAMPLE_FILES = androidtv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


