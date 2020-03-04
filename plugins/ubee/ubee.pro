include(ubee.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ubee.h

SOURCES = ubee.cpp

TARGET = $$qtLibraryTarget(ubee)

DESTDIR = ../../plugins

EXAMPLE_FILES = ubee.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


