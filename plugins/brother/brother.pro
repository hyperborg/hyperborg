include(brother.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = brother.h

SOURCES = brother.cpp

TARGET = $$qtLibraryTarget(brother)

DESTDIR = ../../plugins

EXAMPLE_FILES = brother.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


