include(somfy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = somfy.h

SOURCES = somfy.cpp

TARGET = $$qtLibraryTarget(somfy)

DESTDIR = ../../plugins

EXAMPLE_FILES = somfy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


