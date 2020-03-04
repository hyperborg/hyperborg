include(rainforest_eagle.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rainforest_eagle.h

SOURCES = rainforest_eagle.cpp

TARGET = $$qtLibraryTarget(rainforest_eagle)

DESTDIR = ../../plugins

EXAMPLE_FILES = rainforest_eagle.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


