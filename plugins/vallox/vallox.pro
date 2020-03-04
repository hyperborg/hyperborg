include(vallox.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = vallox.h

SOURCES = vallox.cpp

TARGET = $$qtLibraryTarget(vallox)

DESTDIR = ../../plugins

EXAMPLE_FILES = vallox.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


