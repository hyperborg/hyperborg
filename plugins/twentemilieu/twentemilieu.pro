include(twentemilieu.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = twentemilieu.h

SOURCES = twentemilieu.cpp

TARGET = $$qtLibraryTarget(twentemilieu)

DESTDIR = ../../plugins

EXAMPLE_FILES = twentemilieu.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


