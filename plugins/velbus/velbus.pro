include(velbus.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = velbus.h

SOURCES = velbus.cpp

TARGET = $$qtLibraryTarget(velbus)

DESTDIR = ../../plugins

EXAMPLE_FILES = velbus.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


