include(pyload.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pyload.h

SOURCES = pyload.cpp

TARGET = $$qtLibraryTarget(pyload)

DESTDIR = ../../plugins

EXAMPLE_FILES = pyload.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


