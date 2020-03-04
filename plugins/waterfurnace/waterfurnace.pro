include(waterfurnace.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = waterfurnace.h

SOURCES = waterfurnace.cpp

TARGET = $$qtLibraryTarget(waterfurnace)

DESTDIR = ../../plugins

EXAMPLE_FILES = waterfurnace.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


