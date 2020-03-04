include(snapcast.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = snapcast.h

SOURCES = snapcast.cpp

TARGET = $$qtLibraryTarget(snapcast)

DESTDIR = ../../plugins

EXAMPLE_FILES = snapcast.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


