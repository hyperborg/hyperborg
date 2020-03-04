include(linky.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = linky.h

SOURCES = linky.cpp

TARGET = $$qtLibraryTarget(linky)

DESTDIR = ../../plugins

EXAMPLE_FILES = linky.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


