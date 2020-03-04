include(folder.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = folder.h

SOURCES = folder.cpp

TARGET = $$qtLibraryTarget(folder)

DESTDIR = ../../plugins

EXAMPLE_FILES = folder.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


