include(myq.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = myq.h

SOURCES = myq.cpp

TARGET = $$qtLibraryTarget(myq)

DESTDIR = ../../plugins

EXAMPLE_FILES = myq.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


