include(sht31.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sht31.h

SOURCES = sht31.cpp

TARGET = $$qtLibraryTarget(sht31)

DESTDIR = ../../plugins

EXAMPLE_FILES = sht31.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


