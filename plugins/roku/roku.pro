include(roku.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = roku.h

SOURCES = roku.cpp

TARGET = $$qtLibraryTarget(roku)

DESTDIR = ../../plugins

EXAMPLE_FILES = roku.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


