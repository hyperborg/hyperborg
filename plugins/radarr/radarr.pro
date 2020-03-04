include(radarr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = radarr.h

SOURCES = radarr.cpp

TARGET = $$qtLibraryTarget(radarr)

DESTDIR = ../../plugins

EXAMPLE_FILES = radarr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


