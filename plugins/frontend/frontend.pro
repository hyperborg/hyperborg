include(frontend.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = frontend.h

SOURCES = frontend.cpp

TARGET = $$qtLibraryTarget(frontend)

DESTDIR = ../../plugins

EXAMPLE_FILES = frontend.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


