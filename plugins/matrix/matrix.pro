include(matrix.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = matrix.h

SOURCES = matrix.cpp

TARGET = $$qtLibraryTarget(matrix)

DESTDIR = ../../plugins

EXAMPLE_FILES = matrix.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


