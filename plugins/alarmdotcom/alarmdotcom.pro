include(alarmdotcom.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = alarmdotcom.h

SOURCES = alarmdotcom.cpp

TARGET = $$qtLibraryTarget(alarmdotcom)

DESTDIR = ../../plugins

EXAMPLE_FILES = alarmdotcom.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


