include(dunehd.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = dunehd.h

SOURCES = dunehd.cpp

TARGET = $$qtLibraryTarget(dunehd)

DESTDIR = ../../plugins

EXAMPLE_FILES = dunehd.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


