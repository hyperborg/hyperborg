include(yamaha_musiccast.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yamaha_musiccast.h

SOURCES = yamaha_musiccast.cpp

TARGET = $$qtLibraryTarget(yamaha_musiccast)

DESTDIR = ../../plugins

EXAMPLE_FILES = yamaha_musiccast.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


