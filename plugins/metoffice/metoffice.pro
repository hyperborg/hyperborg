include(metoffice.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = metoffice.h

SOURCES = metoffice.cpp

TARGET = $$qtLibraryTarget(metoffice)

DESTDIR = ../../plugins

EXAMPLE_FILES = metoffice.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


