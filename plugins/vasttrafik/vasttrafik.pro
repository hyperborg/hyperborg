include(vasttrafik.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vasttrafik.h

SOURCES = vasttrafik.cpp

TARGET = $$qtLibraryTarget(vasttrafik)

DESTDIR = ../../plugins

EXAMPLE_FILES = vasttrafik.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


