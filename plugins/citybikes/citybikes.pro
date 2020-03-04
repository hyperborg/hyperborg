include(citybikes.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = citybikes.h

SOURCES = citybikes.cpp

TARGET = $$qtLibraryTarget(citybikes)

DESTDIR = ../../plugins

EXAMPLE_FILES = citybikes.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


