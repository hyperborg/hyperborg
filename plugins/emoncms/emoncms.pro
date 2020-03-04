include(emoncms.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = emoncms.h

SOURCES = emoncms.cpp

TARGET = $$qtLibraryTarget(emoncms)

DESTDIR = ../../plugins

EXAMPLE_FILES = emoncms.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


