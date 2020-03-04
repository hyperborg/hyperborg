include(proxy.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = proxy.h

SOURCES = proxy.cpp

TARGET = $$qtLibraryTarget(proxy)

DESTDIR = ../../plugins

EXAMPLE_FILES = proxy.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


