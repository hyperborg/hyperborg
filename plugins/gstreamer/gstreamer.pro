include(gstreamer.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = gstreamer.h

SOURCES = gstreamer.cpp

TARGET = $$qtLibraryTarget(gstreamer)

DESTDIR = ../../plugins

EXAMPLE_FILES = gstreamer.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


