include(oem.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = oem.h

SOURCES = oem.cpp

TARGET = $$qtLibraryTarget(oem)

DESTDIR = ../../plugins

EXAMPLE_FILES = oem.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


