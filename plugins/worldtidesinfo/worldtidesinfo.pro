include(worldtidesinfo.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = worldtidesinfo.h

SOURCES = worldtidesinfo.cpp

TARGET = $$qtLibraryTarget(worldtidesinfo)

DESTDIR = ../../plugins

EXAMPLE_FILES = worldtidesinfo.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


