include(shiftr.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = shiftr.h

SOURCES = shiftr.cpp

TARGET = $$qtLibraryTarget(shiftr)

DESTDIR = ../../plugins

EXAMPLE_FILES = shiftr.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


