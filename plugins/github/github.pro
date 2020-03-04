include(github.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = github.h

SOURCES = github.cpp

TARGET = $$qtLibraryTarget(github)

DESTDIR = ../../plugins

EXAMPLE_FILES = github.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


