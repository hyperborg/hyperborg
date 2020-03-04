include(litejet.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = litejet.h

SOURCES = litejet.cpp

TARGET = $$qtLibraryTarget(litejet)

DESTDIR = ../../plugins

EXAMPLE_FILES = litejet.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


