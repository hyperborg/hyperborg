include(airvisual.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = airvisual.h

SOURCES = airvisual.cpp

TARGET = $$qtLibraryTarget(airvisual)

DESTDIR = ../../plugins

EXAMPLE_FILES = airvisual.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


