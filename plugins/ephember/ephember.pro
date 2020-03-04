include(ephember.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = ephember.h

SOURCES = ephember.cpp

TARGET = $$qtLibraryTarget(ephember)

DESTDIR = ../../plugins

EXAMPLE_FILES = ephember.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


