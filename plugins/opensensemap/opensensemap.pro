include(opensensemap.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = opensensemap.h

SOURCES = opensensemap.cpp

TARGET = $$qtLibraryTarget(opensensemap)

DESTDIR = ../../plugins

EXAMPLE_FILES = opensensemap.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


