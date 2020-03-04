include(elgato.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = elgato.h

SOURCES = elgato.cpp

TARGET = $$qtLibraryTarget(elgato)

DESTDIR = ../../plugins

EXAMPLE_FILES = elgato.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


