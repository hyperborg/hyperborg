include(sky_hub.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sky_hub.h

SOURCES = sky_hub.cpp

TARGET = $$qtLibraryTarget(sky_hub)

DESTDIR = ../../plugins

EXAMPLE_FILES = sky_hub.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


