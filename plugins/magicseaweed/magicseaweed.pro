include(magicseaweed.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = magicseaweed.h

SOURCES = magicseaweed.cpp

TARGET = $$qtLibraryTarget(magicseaweed)

DESTDIR = ../../plugins

EXAMPLE_FILES = magicseaweed.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


