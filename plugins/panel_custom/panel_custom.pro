include(panel_custom.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = panel_custom.h

SOURCES = panel_custom.cpp

TARGET = $$qtLibraryTarget(panel_custom)

DESTDIR = ../../plugins

EXAMPLE_FILES = panel_custom.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


