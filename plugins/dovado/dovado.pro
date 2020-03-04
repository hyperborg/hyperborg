include(dovado.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dovado.h

SOURCES = dovado.cpp

TARGET = $$qtLibraryTarget(dovado)

DESTDIR = ../../plugins

EXAMPLE_FILES = dovado.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


