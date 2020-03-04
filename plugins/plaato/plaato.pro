include(plaato.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = plaato.h

SOURCES = plaato.cpp

TARGET = $$qtLibraryTarget(plaato)

DESTDIR = ../../plugins

EXAMPLE_FILES = plaato.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


