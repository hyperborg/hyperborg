include(buienradar.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = buienradar.h

SOURCES = buienradar.cpp

TARGET = $$qtLibraryTarget(buienradar)

DESTDIR = ../../plugins

EXAMPLE_FILES = buienradar.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


