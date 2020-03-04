include(anthemav.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = anthemav.h

SOURCES = anthemav.cpp

TARGET = $$qtLibraryTarget(anthemav)

DESTDIR = ../../plugins

EXAMPLE_FILES = anthemav.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


