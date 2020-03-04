include(sma.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sma.h

SOURCES = sma.cpp

TARGET = $$qtLibraryTarget(sma)

DESTDIR = ../../plugins

EXAMPLE_FILES = sma.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


