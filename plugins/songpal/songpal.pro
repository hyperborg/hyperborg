include(songpal.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = songpal.h

SOURCES = songpal.cpp

TARGET = $$qtLibraryTarget(songpal)

DESTDIR = ../../plugins

EXAMPLE_FILES = songpal.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


