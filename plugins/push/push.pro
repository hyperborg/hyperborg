include(push.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = push.h

SOURCES = push.cpp

TARGET = $$qtLibraryTarget(push)

DESTDIR = ../../plugins

EXAMPLE_FILES = push.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


