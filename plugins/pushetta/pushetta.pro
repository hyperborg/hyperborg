include(pushetta.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = pushetta.h

SOURCES = pushetta.cpp

TARGET = $$qtLibraryTarget(pushetta)

DESTDIR = ../../plugins

EXAMPLE_FILES = pushetta.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


