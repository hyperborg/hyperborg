include(mvglive.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = mvglive.h

SOURCES = mvglive.cpp

TARGET = $$qtLibraryTarget(mvglive)

DESTDIR = ../../plugins

EXAMPLE_FILES = mvglive.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


