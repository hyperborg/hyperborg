include(sesame.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = sesame.h

SOURCES = sesame.cpp

TARGET = $$qtLibraryTarget(sesame)

DESTDIR = ../../plugins

EXAMPLE_FILES = sesame.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


