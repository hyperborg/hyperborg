include(luci.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = luci.h

SOURCES = luci.cpp

TARGET = $$qtLibraryTarget(luci)

DESTDIR = ../../plugins

EXAMPLE_FILES = luci.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


