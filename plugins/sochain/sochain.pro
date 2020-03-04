include(sochain.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sochain.h

SOURCES = sochain.cpp

TARGET = $$qtLibraryTarget(sochain)

DESTDIR = ../../plugins

EXAMPLE_FILES = sochain.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


