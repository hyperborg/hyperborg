include(iaqualink.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = iaqualink.h

SOURCES = iaqualink.cpp

TARGET = $$qtLibraryTarget(iaqualink)

DESTDIR = ../../plugins

EXAMPLE_FILES = iaqualink.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


