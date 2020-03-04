include(gogogate2.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gogogate2.h

SOURCES = gogogate2.cpp

TARGET = $$qtLibraryTarget(gogogate2)

DESTDIR = ../../plugins

EXAMPLE_FILES = gogogate2.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


