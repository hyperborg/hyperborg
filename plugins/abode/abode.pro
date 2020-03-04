include(abode.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = abode.h

SOURCES = abode.cpp

TARGET = $$qtLibraryTarget(abode)

DESTDIR = ../../plugins

EXAMPLE_FILES = abode.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


