include(airly.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = airly.h

SOURCES = airly.cpp

TARGET = $$qtLibraryTarget(airly)

DESTDIR = ../../plugins

EXAMPLE_FILES = airly.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


