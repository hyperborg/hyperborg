include(almond.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = almond.h

SOURCES = almond.cpp

TARGET = $$qtLibraryTarget(almond)

DESTDIR = ../../plugins

EXAMPLE_FILES = almond.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


