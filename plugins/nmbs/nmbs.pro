include(nmbs.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = nmbs.h

SOURCES = nmbs.cpp

TARGET = $$qtLibraryTarget(nmbs)

DESTDIR = ../../plugins

EXAMPLE_FILES = nmbs.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


