include(synologydsm.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = synologydsm.h

SOURCES = synologydsm.cpp

TARGET = $$qtLibraryTarget(synologydsm)

DESTDIR = ../../plugins

EXAMPLE_FILES = synologydsm.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


