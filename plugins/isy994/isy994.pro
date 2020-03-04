include(isy994.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = isy994.h

SOURCES = isy994.cpp

TARGET = $$qtLibraryTarget(isy994)

DESTDIR = ../../plugins

EXAMPLE_FILES = isy994.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


