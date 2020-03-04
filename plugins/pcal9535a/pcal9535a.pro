include(pcal9535a.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pcal9535a.h

SOURCES = pcal9535a.cpp

TARGET = $$qtLibraryTarget(pcal9535a)

DESTDIR = ../../plugins

EXAMPLE_FILES = pcal9535a.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


