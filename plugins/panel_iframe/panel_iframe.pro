include(panel_iframe.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = panel_iframe.h

SOURCES = panel_iframe.cpp

TARGET = $$qtLibraryTarget(panel_iframe)

DESTDIR = ../../plugins

EXAMPLE_FILES = panel_iframe.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


