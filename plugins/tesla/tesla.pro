include(tesla.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tesla.h

SOURCES = tesla.cpp

TARGET = $$qtLibraryTarget(tesla)

DESTDIR = ../../plugins

EXAMPLE_FILES = tesla.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


