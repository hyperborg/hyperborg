include(squeezebox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = squeezebox.h

SOURCES = squeezebox.cpp

TARGET = $$qtLibraryTarget(squeezebox)

DESTDIR = ../../plugins

EXAMPLE_FILES = squeezebox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


