include(http.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = http.h

SOURCES = http.cpp

TARGET = $$qtLibraryTarget(http)

DESTDIR = ../../plugins

EXAMPLE_FILES = http.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


