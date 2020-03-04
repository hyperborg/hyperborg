include(lastfm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lastfm.h

SOURCES = lastfm.cpp

TARGET = $$qtLibraryTarget(lastfm)

DESTDIR = ../../plugins

EXAMPLE_FILES = lastfm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


