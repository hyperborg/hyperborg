include(testplugin.pri)

TEMPLATE=lib
CONFIG 	+=plugin
QT 	+= xml

INCLUDEPATH +=../../common

HEADER = testplugin.h

SOURCES = testplugin.cpp

TARGET = $$qtLibraryTarget(testplugin)

DESTDIR = ../../plugins

EXAMPLE_FILES = testplugin.json

MOC_DIR=../../.build/.moc
OBJECTS_DIR=../../.build/.objs
RCC_DIR=../../.build/.rcc
UI_DIR=../../.build/.uic


