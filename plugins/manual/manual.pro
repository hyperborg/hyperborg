include(manual.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = manual.h

SOURCES = manual.cpp

TARGET = $$qtLibraryTarget(manual)

DESTDIR = ../../plugins

EXAMPLE_FILES = manual.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


