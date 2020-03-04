include(kankun.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = kankun.h

SOURCES = kankun.cpp

TARGET = $$qtLibraryTarget(kankun)

DESTDIR = ../../plugins

EXAMPLE_FILES = kankun.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


