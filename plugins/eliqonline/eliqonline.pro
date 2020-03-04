include(eliqonline.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = eliqonline.h

SOURCES = eliqonline.cpp

TARGET = $$qtLibraryTarget(eliqonline)

DESTDIR = ../../plugins

EXAMPLE_FILES = eliqonline.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


