include(directv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = directv.h

SOURCES = directv.cpp

TARGET = $$qtLibraryTarget(directv)

DESTDIR = ../../plugins

EXAMPLE_FILES = directv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


