include(sonarr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sonarr.h

SOURCES = sonarr.cpp

TARGET = $$qtLibraryTarget(sonarr)

DESTDIR = ../../plugins

EXAMPLE_FILES = sonarr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


