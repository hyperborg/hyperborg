include(sensehat.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sensehat.h

SOURCES = sensehat.cpp

TARGET = $$qtLibraryTarget(sensehat)

DESTDIR = ../../plugins

EXAMPLE_FILES = sensehat.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


