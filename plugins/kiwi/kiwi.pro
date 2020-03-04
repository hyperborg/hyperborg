include(kiwi.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = kiwi.h

SOURCES = kiwi.cpp

TARGET = $$qtLibraryTarget(kiwi)

DESTDIR = ../../plugins

EXAMPLE_FILES = kiwi.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


