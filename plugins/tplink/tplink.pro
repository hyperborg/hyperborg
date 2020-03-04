include(tplink.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tplink.h

SOURCES = tplink.cpp

TARGET = $$qtLibraryTarget(tplink)

DESTDIR = ../../plugins

EXAMPLE_FILES = tplink.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


