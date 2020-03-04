include(lcn.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = lcn.h

SOURCES = lcn.cpp

TARGET = $$qtLibraryTarget(lcn)

DESTDIR = ../../plugins

EXAMPLE_FILES = lcn.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


