include(smhi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = smhi.h

SOURCES = smhi.cpp

TARGET = $$qtLibraryTarget(smhi)

DESTDIR = ../../plugins

EXAMPLE_FILES = smhi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


