include(yeelight.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yeelight.h

SOURCES = yeelight.cpp

TARGET = $$qtLibraryTarget(yeelight)

DESTDIR = ../../plugins

EXAMPLE_FILES = yeelight.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


