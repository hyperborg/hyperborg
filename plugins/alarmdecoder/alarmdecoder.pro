include(alarmdecoder.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = alarmdecoder.h

SOURCES = alarmdecoder.cpp

TARGET = $$qtLibraryTarget(alarmdecoder)

DESTDIR = ../../plugins

EXAMPLE_FILES = alarmdecoder.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


