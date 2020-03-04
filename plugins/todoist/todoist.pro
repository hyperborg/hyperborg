include(todoist.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = todoist.h

SOURCES = todoist.cpp

TARGET = $$qtLibraryTarget(todoist)

DESTDIR = ../../plugins

EXAMPLE_FILES = todoist.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


