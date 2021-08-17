include(ws.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= 

INCLUDEPATH +=../../common

HEADER = ws.h

SOURCES = ws.cpp

TARGET = $$qtLibraryTarget(ws)

DESTDIR = ../../plugins

EXAMPLE_FILES = ws.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic

