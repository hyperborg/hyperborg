include(openuv.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = openuv.h

SOURCES = openuv.cpp

TARGET = $$qtLibraryTarget(openuv)

DESTDIR = ../../plugins

EXAMPLE_FILES = openuv.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


