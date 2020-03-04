include(picotts.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = picotts.h

SOURCES = picotts.cpp

TARGET = $$qtLibraryTarget(picotts)

DESTDIR = ../../plugins

EXAMPLE_FILES = picotts.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


