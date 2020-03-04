include(free_mobile.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = free_mobile.h

SOURCES = free_mobile.cpp

TARGET = $$qtLibraryTarget(free_mobile)

DESTDIR = ../../plugins

EXAMPLE_FILES = free_mobile.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


