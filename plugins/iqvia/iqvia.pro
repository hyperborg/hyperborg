include(iqvia.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = iqvia.h

SOURCES = iqvia.cpp

TARGET = $$qtLibraryTarget(iqvia)

DESTDIR = ../../plugins

EXAMPLE_FILES = iqvia.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


