include(keyboard.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = keyboard.h

SOURCES = keyboard.cpp

TARGET = $$qtLibraryTarget(keyboard)

DESTDIR = ../../plugins

EXAMPLE_FILES = keyboard.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


