include(vacuum.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vacuum.h

SOURCES = vacuum.cpp

TARGET = $$qtLibraryTarget(vacuum)

DESTDIR = ../../plugins

EXAMPLE_FILES = vacuum.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


