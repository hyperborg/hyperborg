include(osramlightify.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = osramlightify.h

SOURCES = osramlightify.cpp

TARGET = $$qtLibraryTarget(osramlightify)

DESTDIR = ../../plugins

EXAMPLE_FILES = osramlightify.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


