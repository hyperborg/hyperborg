include(ambiclimate.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ambiclimate.h

SOURCES = ambiclimate.cpp

TARGET = $$qtLibraryTarget(ambiclimate)

DESTDIR = ../../plugins

EXAMPLE_FILES = ambiclimate.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


