include(opencv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = opencv.h

SOURCES = opencv.cpp

TARGET = $$qtLibraryTarget(opencv)

DESTDIR = ../../plugins

EXAMPLE_FILES = opencv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


