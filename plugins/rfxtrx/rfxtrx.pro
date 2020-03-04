include(rfxtrx.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = rfxtrx.h

SOURCES = rfxtrx.cpp

TARGET = $$qtLibraryTarget(rfxtrx)

DESTDIR = ../../plugins

EXAMPLE_FILES = rfxtrx.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


