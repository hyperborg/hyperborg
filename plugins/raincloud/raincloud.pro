include(raincloud.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = raincloud.h

SOURCES = raincloud.cpp

TARGET = $$qtLibraryTarget(raincloud)

DESTDIR = ../../plugins

EXAMPLE_FILES = raincloud.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


