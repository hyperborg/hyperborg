include(flexit.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = flexit.h

SOURCES = flexit.cpp

TARGET = $$qtLibraryTarget(flexit)

DESTDIR = ../../plugins

EXAMPLE_FILES = flexit.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


