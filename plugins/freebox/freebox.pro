include(freebox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = freebox.h

SOURCES = freebox.cpp

TARGET = $$qtLibraryTarget(freebox)

DESTDIR = ../../plugins

EXAMPLE_FILES = freebox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


