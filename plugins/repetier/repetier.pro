include(repetier.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = repetier.h

SOURCES = repetier.cpp

TARGET = $$qtLibraryTarget(repetier)

DESTDIR = ../../plugins

EXAMPLE_FILES = repetier.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


