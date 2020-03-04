include(smarty.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = smarty.h

SOURCES = smarty.cpp

TARGET = $$qtLibraryTarget(smarty)

DESTDIR = ../../plugins

EXAMPLE_FILES = smarty.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


