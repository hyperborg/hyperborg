include(file.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = file.h

SOURCES = file.cpp

TARGET = $$qtLibraryTarget(file)

DESTDIR = ../../plugins

EXAMPLE_FILES = file.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


