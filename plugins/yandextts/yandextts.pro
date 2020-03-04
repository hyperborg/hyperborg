include(yandextts.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = yandextts.h

SOURCES = yandextts.cpp

TARGET = $$qtLibraryTarget(yandextts)

DESTDIR = ../../plugins

EXAMPLE_FILES = yandextts.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


