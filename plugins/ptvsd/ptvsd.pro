include(ptvsd.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ptvsd.h

SOURCES = ptvsd.cpp

TARGET = $$qtLibraryTarget(ptvsd)

DESTDIR = ../../plugins

EXAMPLE_FILES = ptvsd.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


