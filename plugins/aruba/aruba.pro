include(aruba.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = aruba.h

SOURCES = aruba.cpp

TARGET = $$qtLibraryTarget(aruba)

DESTDIR = ../../plugins

EXAMPLE_FILES = aruba.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


