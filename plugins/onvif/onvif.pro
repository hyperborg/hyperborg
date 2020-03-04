include(onvif.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = onvif.h

SOURCES = onvif.cpp

TARGET = $$qtLibraryTarget(onvif)

DESTDIR = ../../plugins

EXAMPLE_FILES = onvif.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


