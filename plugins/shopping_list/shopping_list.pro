include(shopping_list.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = shopping_list.h

SOURCES = shopping_list.cpp

TARGET = $$qtLibraryTarget(shopping_list)

DESTDIR = ../../plugins

EXAMPLE_FILES = shopping_list.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


