include(emulated_hue.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = emulated_hue.h

SOURCES = emulated_hue.cpp

TARGET = $$qtLibraryTarget(emulated_hue)

DESTDIR = ../../plugins

EXAMPLE_FILES = emulated_hue.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


