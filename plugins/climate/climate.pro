include(climate.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = climate.h

SOURCES = climate.cpp

TARGET = $$qtLibraryTarget(climate)

DESTDIR = ../../plugins

EXAMPLE_FILES = climate.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


