include(keyboard_remote.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = keyboard_remote.h

SOURCES = keyboard_remote.cpp

TARGET = $$qtLibraryTarget(keyboard_remote)

DESTDIR = ../../plugins

EXAMPLE_FILES = keyboard_remote.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


