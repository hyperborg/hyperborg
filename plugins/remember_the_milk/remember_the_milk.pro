include(remember_the_milk.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = remember_the_milk.h

SOURCES = remember_the_milk.cpp

TARGET = $$qtLibraryTarget(remember_the_milk)

DESTDIR = ../../plugins

EXAMPLE_FILES = remember_the_milk.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


