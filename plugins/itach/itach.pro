include(itach.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = itach.h

SOURCES = itach.cpp

TARGET = $$qtLibraryTarget(itach)

DESTDIR = ../../plugins

EXAMPLE_FILES = itach.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


