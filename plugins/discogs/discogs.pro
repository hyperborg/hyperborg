include(discogs.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = discogs.h

SOURCES = discogs.cpp

TARGET = $$qtLibraryTarget(discogs)

DESTDIR = ../../plugins

EXAMPLE_FILES = discogs.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


