include(clickatell.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = clickatell.h

SOURCES = clickatell.cpp

TARGET = $$qtLibraryTarget(clickatell)

DESTDIR = ../../plugins

EXAMPLE_FILES = clickatell.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


