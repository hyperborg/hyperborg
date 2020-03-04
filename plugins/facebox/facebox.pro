include(facebox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = facebox.h

SOURCES = facebox.cpp

TARGET = $$qtLibraryTarget(facebox)

DESTDIR = ../../plugins

EXAMPLE_FILES = facebox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


