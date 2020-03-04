include(tplink_lte.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = tplink_lte.h

SOURCES = tplink_lte.cpp

TARGET = $$qtLibraryTarget(tplink_lte)

DESTDIR = ../../plugins

EXAMPLE_FILES = tplink_lte.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


