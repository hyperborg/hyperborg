include(juicenet.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = juicenet.h

SOURCES = juicenet.cpp

TARGET = $$qtLibraryTarget(juicenet)

DESTDIR = ../../plugins

EXAMPLE_FILES = juicenet.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


