include(n26.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = n26.h

SOURCES = n26.cpp

TARGET = $$qtLibraryTarget(n26)

DESTDIR = ../../plugins

EXAMPLE_FILES = n26.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


