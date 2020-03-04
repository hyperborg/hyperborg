include(timer.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = timer.h

SOURCES = timer.cpp

TARGET = $$qtLibraryTarget(timer)

DESTDIR = ../../plugins

EXAMPLE_FILES = timer.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


