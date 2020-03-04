include(ombi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ombi.h

SOURCES = ombi.cpp

TARGET = $$qtLibraryTarget(ombi)

DESTDIR = ../../plugins

EXAMPLE_FILES = ombi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


