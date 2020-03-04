include(keba.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = keba.h

SOURCES = keba.cpp

TARGET = $$qtLibraryTarget(keba)

DESTDIR = ../../plugins

EXAMPLE_FILES = keba.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


