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
